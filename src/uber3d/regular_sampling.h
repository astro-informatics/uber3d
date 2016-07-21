
#ifndef REGULAR_SAMPLING_H
#define REGULAR_SAMPLING_H

#include <string>
#include "radial_sampling.h"


namespace uber3d {


/**
  * class regular_sampling
  * 
  */
class regular_sampling : virtual public radial_sampling
{
public:

  // Constructors/Destructors
  //  

  // Static Public attributes
  //  

  // Public attributes
  //


private:

  // Private attributes
  //  

  // Maximum radius
  double r_max;


};
} // end of package namespace

#endif // REGULAR_SAMPLING_H
