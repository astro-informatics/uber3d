
#ifndef REGULAR_SAMPLING_H
#define REGULAR_SAMPLING_H

#include <string>
#include <iostream>
#include <math.h>
#include "radial_sampling.h"


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
   
   // Member functions implementing the radial_sampling interface
   //
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
   inline long get_nsamp(){
       return N;
   }
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