
#ifndef REGULAR_SAMPLING_H
#define REGULAR_SAMPLING_H

#include <string>
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
   * Spherical Bessel function of order 0.
   * Manually specifying a number \N of samples implies that the SFBT will only
   * be able to be evaluated up to a given Kmax.
   * \param  Rmax  Maximum radius 
   * \param  Nsamp Number of radial samples
   */
   bessel_sampling(double Rmax, long Nsamp): N(Nsamp), r_max(Rmax)   
   {
       
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
   
   }
   
   // Member functions implementing the radial_sampling interface
   //
   /**
   * Returns the radius for the  provided radial index
   * \return double
   * \param  ind Radial index
   */
   virtual double get_r(long ind){
        
   }
   /**
   * Returns the number of radial samples
   * \return long
   */
   virtual long get_nsamp(){
       return N;
   }
   /**
    * Builds a Spherical Bessel Transform for the this radial sampling scheme
    * \return uber3d::radial_transform
    */
   virtual uber3d::radial_transform build_sbt (){
       
   }

    /**
    * Builds a Laguerre transform for this radial sampling scheme
    * \return uber3d::radial_transform
    */
    virtual uber3d::radial_transform build_laguerre_transform (){
    
        
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

};
} // end of package namespace

#endif // REGULAR_SAMPLING_H
