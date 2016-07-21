
#ifndef RADIAL_TRANSFORM_H
#define RADIAL_TRANSFORM_H

#include <string>
#include "datatypes.h"
#include "arr.h"

namespace uber3d {


/**
  * class radial_transform
  * 
  */

/******************************* Abstract Class ****************************
radial_transform does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/


class radial_transform
{
public:


  /**
   * Computes forward radial transform along a line of sight
   * \param  in_los Input line of sight
   * \param  out_coeff Output coefficients
   */
  virtual void forward (arr<float> in_los, arr<fcomplex> out_coeff) { }
  virtual void forward (arr<double> in_los, arr<dcomplex> out_coeff) { }


  /**
   * Computes backward transform from coefficients to line of sight
   * \param  in_coeff Input coefficients
   * \param  out_los Output line of sight
   */
  virtual void backward (arr<float> in_coeff, arr<fcomplex> out_los) { }
  virtual void backward (arr<double> in_coeff, arr<dcomplex> out_los) { }


};
} // end of package namespace

#endif // RADIAL_TRANSFORM_H
