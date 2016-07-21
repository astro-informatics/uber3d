
#ifndef RADIAL_SAMPLING_H
#define RADIAL_SAMPLING_H

#include <string>
#include "radial_transform.h"


namespace uber3d {


/**
  * class radial_sampling
  * 
  */

/******************************* Abstract Class ****************************
radial_sampling does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class radial_sampling
{
public:

   // Virtual destructor
   virtual ~radial_sampling() {}

  /**
   * Returns the radius for the  provided radial index
   * \return double
   * \param  ind Radial index
   */
  virtual double get_r (long ind) = 0;

  /**
   * Returns the number of radial samples
   * \return long
   */
  virtual long get_nsamp () = 0;

  /**
   * Builds a Spherical Bessel Transform for the this radial sampling scheme
   * \return uber3d::radial_transform
   */
  virtual uber3d::radial_transform build_sbt () = 0;


  /**
   * Builds a Laguerre transform for this radial sampling scheme
   * \return uber3d::radial_transform
   */
  virtual uber3d::radial_transform build_laguerre_transform () = 0;

};
} // end of package namespace

#endif // RADIAL_SAMPLING_H
