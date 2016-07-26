
#ifndef DSBT_SBT_H
#define DSBT_SBT_H

#include "radial_transform.h"


namespace uber3d{

    
/**
  * class dsbt_sbt
  * 
  * Implements a radial spherical bessel transform based on libdsbt
  * 
  */
class dsbt_sbt: public radial_transform
{
    
  /**
   * Computes forward radial transform along a line of sight
   * \param  in_los Input line of sight
   * \param  out_coeff Output coefficients
   */
  virtual void forward (const arr<float> &in_los, arr<fcomplex> &out_coeff) { }
  virtual void forward (const arr<double> &in_los, arr<dcomplex> &out_coeff) { }

  /**
   * Computes backward transform from coefficients to line of sight
   * \param  in_coeff Input coefficients
   * \param  out_los Output line of sight
   */
  virtual void backward (const arr<float> &in_coeff, arr<fcomplex> &out_los) { }
  virtual void backward (const arr<double> &in_coeff, arr<dcomplex> &out_los) { }

};
} // end of package namespace

#endif // DSBT_SBT_H
