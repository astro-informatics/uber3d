
#ifndef SHT_H
#define SHT_H

#include <string>
#include "datatypes.h"
#include "arr.h"

namespace uber3d {


/**
  * class sht
  * 
  */

/******************************* Abstract Class ****************************
sht does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class sht
{
public:

  /**
   * Forward SHT transform
   * \param  in_map Input shell
   * \param  out_alm output spherical harmonic coefficients
   */
  virtual void forward (arr<double> &in_map, arr<dcomplex> &out_alm) = 0;

  /**
   * Backward spherical harmonics coefficients
   * \param  in_alm Input spherical harmonics coefficients
   * \param  out_shell Ouput spherical shell
   */
  virtual void backward (arr<dcomplex> &in_alm, arr<double> &out_shell) = 0;


};
} // end of package namespace

#endif // SHT_H
