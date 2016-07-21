
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
  virtual void forward (arr<float> in_map, arr<fcomplex> out_alm) { }
  virtual void forward (arr<double> in_map, arr<dcomplex> out_alm) { }


  /**
   * Backward spherical harmonics coefficients
   * \param  in_alm Input spherical harmonics coefficients
   * \param  out_shell Ouput spherical shell
   */
  virtual void backward (arr<float> in_alm, arr<fcomplex> out_shell) { }
  virtual void backward (arr<double> in_alm, arr<dcomplex> out_shell) { }


};
} // end of package namespace

#endif // SHT_H
