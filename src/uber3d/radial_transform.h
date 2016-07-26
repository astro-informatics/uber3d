
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
  virtual void forward (const arr<float> &in_los, arr<float> &out_coeff) = 0;
  virtual void forward (const arr<double> &in_los, arr<double> &out_coeff) = 0;


  /**
   * Computes backward transform from coefficients to line of sight
   * \param  in_coeff Input coefficients
   * \param  out_los Output line of sight
   */
  virtual void backward (const arr<float> &in_coeff, arr<float> &out_los) = 0;
  virtual void backward (const arr<double> &in_coeff, arr<double> &out_los) = 0;


};
} // end of package namespace

#endif // RADIAL_TRANSFORM_H
