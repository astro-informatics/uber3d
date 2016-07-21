
#ifndef SFB_TRANSFORM_H
#define SFB_TRANSFORM_H

#include <string>
#include "map.h"
#include "sfb_coefficients.h"

namespace uber3d {


/**
  * class sfb_transform
  * 
  */
class sfb_transform
{
public:

  // Public attributes
  //  


  // Constructors/Destructors
  //  

  /**
   * Builds a SFB transform based on the specificied radial and  spherical sampling
   * schemes
   * \param  r_samp Radial sampling to use for the transform
   * \param  sph_samp Spherical sampling scheme to use for the transform
   * \param  Lmax Maximum L multipole
   * \param  Nmax Number of K samples
   */
   sfb_transform (const uber3d::radial_sampling &r_samp, const uber3d::spherical_sampling &sph_samp, long Lmax, long Nmax)
  {
  }


  /**
   * Computes the forward Spherical Fourier-Bessel transform
   * \param  in_map Input map to transform
   * \param  out_almn Output Spherical Fourier-Bessel coefficients
   */
  template <typename T1, typename T2>
  void foward (uber3d::map<T1> in_map, uber3d::sfb_coefficients<T2> out_almn)
  {
  }


  /**
   * Computes Backward sfb transform
   * \param  in_almn Input SFB coefficients
   * \param  out_map Reconstructed map
   */
  template <typename T1, typename T2>
  void backward (uber3d::sfb_coefficients<T1> in_almn, uber3d::map<T2> out_map)
  {
  }


};
} // end of package namespace

#endif // SFB_TRANSFORM_H
