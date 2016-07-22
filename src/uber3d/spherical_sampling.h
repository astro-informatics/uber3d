
#ifndef SPHERICAL_SAMPLING_H
#define SPHERICAL_SAMPLING_H

#include <string>
#include "sht.h"

namespace uber3d {


/**
  * class spherical_sampling
  * 
  */

/******************************* Abstract Class ****************************
spherical_sampling does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/


class spherical_sampling
{
public:
    
  // Virtual destructor
  virtual ~spherical_sampling() {}

   /**
    * Returns a newly allocated copy of the sampling scheme
    */
   virtual spherical_sampling *copy() = 0;
  
  /**
   * Returns the  pair (theta, phi) for the pixel of specified index
   * \param  pixel_index Pixel index
   * \param  theta       Output theta
   * \param  phi         Output phi
   */
  virtual void get_theta_phi (uint64_t pixel_index, double &theta, double &phi) = 0;


  /**
   * Returns the pixel index corresponding to specified coordinates
   * \return uint64_t
   * \param  theta
   * \param  phi
   */
   virtual uint64_t get_index (double theta, double phi) = 0;


  /**
   * Returns the number of samples used in this scheme
   * \return uint64_t
   */
   virtual uint64_t get_nsamp () = 0;


  /**
   * Builds a new SHT transform for this sampling scheme
   * \return uber3d::sht
   * \param  lmax Maximum angular multipole
   */
  virtual uber3d::sht build_sht (long lmax) = 0;


};
} // end of package namespace

#endif // SPHERICAL_SAMPLING_H
