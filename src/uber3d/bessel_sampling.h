
#ifndef REGULAR_SAMPLING_H
#define REGULAR_SAMPLING_H

#include <string>
#include <iostream>
#include <math.h>
#include "radial_sampling.h"

#define BESSEL_SAMPLING_NAME "bessel"

namespace uber3d {


/**
  * class regular_sampling
  * 
  */
class bessel_sampling : public radial_sampling
{
public:

  // Constructors/Destructors
  //
  /**
   * Creates an equispaced radial sampling scheme based on the roots of the
   * Spherical Bessel function of order 0 (sinc).
   * Manually specifying a number \N of samples implies that the SFBT will only
   * be able to be evaluated up to a given Kmax.
   * \param  Rmax  Maximum radius 
   * \param  Nsamp Number of radial samples
   */
   bessel_sampling(double Rmax, long Nsamp): N(Nsamp), r_max(Rmax), r_samp(Nsamp)
   {
       // Initialise r_samp with position of sampling points
       for(long i=0; i < N; i++)
           r_samp[i] = M_PI*((double) i);
       
       // Set k_max based on q0Nmax = KmaxRmax
       k_max = M_PI * ((double) N)/Rmax;
   }
   
   /**
   * Creates an equispaced radial sampling scheme based on the roots of the
   * Spherical Bessel function of order 0.
   * Manually specifying a maximum scale \Kmax will choose a number of samples
   * so that the SFB can be evaluated up to this scale.
   * \param  Rmax Maximum radius 
   * \param  Kmax Maximum scale that can be computed with this sampling scheme
   */
   bessel_sampling(double Rmax, double Kmax): r_max(Rmax), k_max(Kmax)
   {
       // Computes N based on q0Nmax = KmaxRmax
       N = r_max * k_max / M_PI;
       
       // Initialise r_samp with position of sampling points
       r_samp.alloc(N);
       for(long i=0; i < N; i++)
           r_samp[i] = M_PI*((double) i);
   }
   
   // Empty constructor
   bessel_sampling(){
        N =0;
        r_max = 1;
        k_max = 1;
   }
   
   // Copy constructor
   bessel_sampling(const bessel_sampling& src){
       N = src.N;
       r_max = src.r_max;
       k_max = src.k_max;
       r_samp =src.r_samp;
   }
   
   // Member functions implementing the radial_sampling interface
   //
   
   /**
    * Returns a newly allocated deep copy of the sampling scheme
    */
   radial_sampling *copy(){
       bessel_sampling *out = new bessel_sampling(*this);
       return out;
   }
   
    void to_HDF5(H5::DataSet dset){
        
        // Create the data to export
        attr_t attr_data;
        attr_data.Nmax = N;
        attr_data.Rmax = r_max;
        
        // Create attribute type
        H5::CompType mtype( sizeof(attr_t) );
        mtype.insertMember( "r_max", HOFFSET(attr_t, Rmax), H5::PredType::NATIVE_DOUBLE);
        mtype.insertMember( "N", HOFFSET(attr_t, Nmax), H5::PredType::NATIVE_LONG);
        
        // Defines dataspace
        const hsize_t attr_dims[1] = { 1 };
        H5::DataSpace attr_dataspace = H5::DataSpace (1, attr_dims);
        
        // Create attribute and add it to the dataset
        H5::Attribute att = dset.createAttribute(BESSEL_SAMPLING_NAME, mtype, attr_dataspace);
        att.write(mtype, &attr_data);
    }
   
    void from_HDF5(H5::DataSet dset){
        
        attr_t attr_data; 
         
        // Create attribute type
        H5::CompType mtype( sizeof(attr_t) );
        mtype.insertMember( "r_max", HOFFSET(attr_t, Rmax), H5::PredType::NATIVE_DOUBLE);
        mtype.insertMember( "N", HOFFSET(attr_t, Nmax), H5::PredType::NATIVE_LONG);
        
        // TODO: Raise an error if attributes not found
        H5::Attribute att = dset.openAttribute(BESSEL_SAMPLING_NAME);
        att.read(mtype, &attr_data);

        // Update sampling scheme based on values read in the file
       N = attr_data.Nmax;
       r_max = attr_data.Rmax;
       r_samp.alloc(N);
       for(long i=0; i < N; i++)
           r_samp[i] = M_PI*((double) i);
       k_max = M_PI * ((double) N)/r_max;
    }
   
   /**
   * Returns the radius for the  provided radial index
   * \return double
   * \param  ind Radial index
   */
   inline double get_r(long ind){
        return r_samp[ind];
   }
   /**
   * Returns the number of radial samples
   * \return long
   */
   inline uint64_t get_nsamp(){
       return N;
   }
   
  /**
   * Returns the name of the sampling scheme
   * \return std::string
   */
  std::string get_name (){
      return std::string(BESSEL_SAMPLING_NAME);
  };
   
   /**
    * Builds a Spherical Bessel Transform for the this radial sampling scheme
    * \return uber3d::radial_transform
    */
   uber3d::radial_transform build_sbt (){
         //TODO: Properly handle these cases
        std::cerr << "SFB transform not implemented for bessel sampling" << std::endl;
        exit(-1);
   }

    /**
    * Builds a Laguerre transform for this radial sampling scheme
    * \return uber3d::radial_transform
    */
    uber3d::radial_transform build_laguerre_transform (){
        //TODO: Properly handle these cases
        std::cerr << "Laguerre transform not implemented for bessel sampling" << std::endl;
        exit(-1);
    }

   
   // Accessors
   //
   inline double get_r_max(){
       return r_max;
    }
   
   inline double get_k_max(){
       return k_max;
    }
   
private:

  // Private attributes
  //  
  typedef struct attr_t{
      double Rmax;
      long Nmax;
  } attr_t;
  
  // Maximum radius
  double r_max;
  // Maximum scale
  double k_max;
  // Number of samples
  long N;

  // Array storing the radial samples
  arr<double> r_samp;
};
} // end of package namespace

#endif // REGULAR_SAMPLING_H
