
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



  /**
   * Returns the  pair (theta, phi) for the pixel of specified index
   * \param  pixel_index Pixel index
   */
  virtual void get_theta_phi (long pixel_index)
  {
  }


  /**
   * Returns the pixel index corresponding to specified coordinates
   * \return long
   * \param  theta
   * \param  phi
   */
  virtual long get_index (double theta, double phi)
  {
  }


  /**
   * Returns the number of pixels used in this sampling scheme
   * \return long
   */
  virtual long get_npix ()
  {
  }


  /**
   * Builds a new SHT transform for this sampling scheme
   * \return uber3d::sht
   * \param  lmax Maximum angular multipole
   */
  virtual uber3d::sht build_sht (long lmax)
  {
  }


};
} // end of package namespace

#endif // SPHERICAL_SAMPLING_H
