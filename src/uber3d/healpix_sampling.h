
#ifndef HEALPIX_SAMPLING_H
#define HEALPIX_SAMPLING_H
#include "spherical_sampling.h"

#include <string>

namespace uber3d {


/**
  * class healpix_sampling
  * 
  */

class healpix_sampling : public spherical_sampling
{

  /**
   * Returns the  pair (theta, phi) for the pixel of specified index
   * \param  pixel_index Pixel index
   */
  virtual void get_theta_phi (long pixel_index) {}


  /**
   * Returns the pixel index corresponding to specified coordinates
   * \return long
   * \param  theta
   * \param  phi
   */
  virtual long get_index (double theta, double phi) {}


  /**
   * Returns the number of pixels used in this sampling scheme
   * \return long
   */
  virtual long get_npix () {}


  /**
   * Builds a new SHT transform for this sampling scheme
   * \return uber3d::sht
   * \param  lmax Maximum angular multipole
   */
  virtual uber3d::sht build_sht (long lmax) {}


};
} // end of package namespace

#endif // HEALPIX_SAMPLING_H
