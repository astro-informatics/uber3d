
#ifndef HEALPIX_SAMPLING_H
#define HEALPIX_SAMPLING_H
#include <string>
#include "spherical_sampling.h"



namespace uber3d {

/**
  * class healpix_sampling
  * 
  */

class healpix_sampling : public spherical_sampling
{
    
public:
  // Constructors/Destructors
  //
  /**
   * Creates an HEALPix spherical sampling scheme.
   * 
   * \param Nside HEALPix nside parameter
   */
   healpix_sampling(int Nside): nside(Nside)
   {
        // Initialises a libsharp 
       
   }
    
  /**
   * Returns the  pair (theta, phi) for the pixel of specified index
   * \param  pixel_index Pixel index
   */
  void get_theta_phi (long pixel_index) {}


  /**
   * Returns the pixel index corresponding to specified coordinates
   * \return long
   * \param  theta
   * \param  phi
   */
   long get_index (double theta, double phi) {}


  /**
   * Returns the number of pixels used in this sampling scheme
   * \return long
   */
   long get_npix () {}


  /**
   * Builds a new SHT transform for this sampling scheme
   * \return uber3d::sht
   * \param  lmax Maximum angular multipole
   */
   uber3d::sht build_sht (long lmax) {}

private:

  // Private attributes
  //  

  // HEALPix nside parameter
  int nside;
  
};
} // end of package namespace

#endif // HEALPIX_SAMPLING_H
