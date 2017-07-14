/*
 * fastDSBT.cpp - This file is part of FastDSBT
 * 
 * Copyright 2011 CEA
 * Contributor : François Lanusse (francois.lanusse@gmail.com)
 * 
 * Created on 04/05/11
 * 
 * This software is a computer program whose purpose is to compute the
 * Spherical Bessel Transform.
 * 
 * This software is governed by the CeCILL  license under French law and
 * abiding by the rules of distribution of free software.  You can  use, 
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info". 
 * 
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability. 
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or 
 * data to be ensured and,  more generally, to use and operate it in the 
 * same conditions as regards security. 
 * 
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 *
 */

#include "fastDSBT.h"

#include <boost/math/special_functions/bessel.hpp>

void FastDSBT::loadBesselZeroes(const char *filename)
{
        int Nmax=0, Lmax=0;
        double val=0;
        bool fileOk = false;
        // try to open the file
        std::ifstream ifile(filename, std::ifstream::binary);
        if(ifile.good()) {
            // Let's try to read the number of zeros
            fileOk = true;
            ifile.read((char *) &Nmax,sizeof(int));
            ifile.read((char *) &Lmax,sizeof(int));
            if(Lmax >= L && Nmax >= N) {
                // Let's read all we can from this file
                for(int l=0; l <= Lmax; l++) {
                    for(int p=0; p <Nmax; p++) {
                        if(! ifile.good()) {
                            fileOk = false;
                            break;
                        }
                        ifile.read((char *) &val,sizeof(double));
                        if( l <= L && p < N) qln[N*l + p] = val;
                    }
                }
            } else {
                fileOk = false;
            }
        }

        // close the file
        ifile.close();


        if(fileOk == false) {
                std::cout << "Computing zeros of Bessel functions...";
            for(int l=0; l <= L; l++) {
                std::vector<double> roots;
                boost::math::cyl_bessel_j_zero(l+0.5, 1, N, std::back_inserter(roots));
                for(int p=0; p <N; p++) {
                    qln[N*l + p] = roots[p];
                }
            }
            std::cout << "Done !" << std::endl;

            // Now we need to save this table so that it can be reused later.
            std::ofstream ofile(filename,  std::ofstream::binary | std::ofstream::trunc);
            if(ofile.good()) {
                Nmax = N;
                Lmax = L;
                ofile.write((char*) &Nmax, sizeof(int));
                ofile.write((char*) &Lmax, sizeof(int));
                for(int l=0; l <= Lmax; l++) {
                    for(int p=0; p <Nmax; p++) {
                        val =  qln[N*l + p];
                        ofile.write((char *) &val, sizeof(double));
                    }
                }
                ofile.close();
            } else {
                std::cout<< "Error, could not save bessel zeros in file " << filename << std::endl;
            }
        }
    }
    
    
    /*! Computes the conversion matrix between orders \a l1 and \a l2. */
    void FastDSBT::computeConversionMatrix(int64_t l1, int64_t l2) {

        if (! initialized) {
            std::cout << "FastDSBT is not initialized" << std::endl;
            return;
        }

        if (!(matrixComputed && l2 == matrixLJ && l2 == matrixLGrid)) {
            computeMatrix(l2,l2);
        }

        double normFactor = sqrt(2.0 * M_PI);
        double tempvalue;

#pragma omp parallel for private(tempvalue)
        for (int64_t q=0; q < N; ++q) {
            for (int64_t n=0; n < N; ++n) {
                tempvalue = boost::math::sph_bessel(l1,qln[(L+1)*n + l2]*qln[(L+1)*q + l1]/qln[(L+1)*(N-1) + l2]);
                for (int64_t p=0; p < N ; ++p) {
                    if (n==0) {
                        conversionMatrix[p*N +q] =0;
                    }
                    conversionMatrix[p*N+q] += tempvalue * transformMatrix[p*N+n];


                    if (n == N -1) {
                        conversionMatrix[p*N + q] = conversionMatrix[p*N + q]  * normFactor/(pow(qln[(L+1)*(N-1) + l2], 3.0) * pow(boost::math::sph_bessel(l1+1, qln[(L+1)*q + l1]),2.0));
                    }
                }
            }
        }

        conversionMatrixL1 = l1;
        conversionMatrixL2 = l2;
        conversionMatrixComputed = true;
    }

    /*! Computes the transform matrix of order \a lj which provides results on the grid of order \a lgrid. */
    void FastDSBT::computeMatrix(int64_t lj, int64_t lgrid) {

        if (! initialized)
            return;

        double normFactor = sqrt(2.0 * M_PI);
        double *weights   = (double *) malloc(N*sizeof(double));
        double tempValue;


#pragma omp parallel private(tempValue)
        {

            if (lj == lgrid) {
#pragma omp for
                for (int64_t p=0; p < N ; ++p) {
                    for (int64_t q=0; q <= p ; ++q) {
                        tempValue = boost::math::sph_bessel(lj, qln[(L+1)*p + lj]*qln[(L+1)*q + lj]/qln[(L+1)*(N-1) + lj]);

                        transformMatrix[p*N + q] = tempValue;
                        if ( p != q)
                            transformMatrix[q*N + p] = tempValue;
                    }

                    tempValue  = boost::math::sph_bessel(lj+1, qln[(L+1)*p + lj]);
                    weights[p] = normFactor/(tempValue*tempValue);
                }
            } else {

#pragma omp for
                for (int64_t p=0; p < N ; ++p) {
                    for (int64_t q=0; q < N ; ++q) {
                        tempValue = boost::math::sph_bessel(lj, qln[(L+1)*p + lgrid]*qln[(L+1)*q + lj]/qln[(L+1)*(N-1) + lgrid]);
                        transformMatrix[p*N + q] = tempValue;
                    }

                    tempValue  = boost::math::sph_bessel(lj+1, qln[(L+1)*p + lj]);
                    weights[p] = normFactor/(tempValue*tempValue);
                }

            }


#pragma omp for
            for (int64_t p=0; p < N ; ++p) {
                for (int64_t q=0; q < N ; ++q) {
                    transformMatrix[p*N + q] = transformMatrix[p*N + q]*weights[q];
                }
            }

        }

        matrixLJ = lj;
        matrixLGrid = lgrid;
        matrixComputed = true;

        free(weights);
    }
