
#ifndef SEPARABLE_TRANSFORM_H
#define SEPARABLE_TRANSFORM_H

#include <string>
#include "sht.h"
#include "radial_transform.h"

namespace uber3d {


/**
  * class separable_transform
  * Base class for  all separable transforms
  */

class separable_transform
{
public:



protected:


  // Protected attributes
  //  

  // Spherical Harmonics Transform to apply on shells
  uber3d::sht * m_sht;
  // Radial transform to apply on lines of sight
  uber3d::radial_transform * m_rt;


};
} // end of package namespace

#endif // SEPARABLE_TRANSFORM_H
