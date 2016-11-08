
#ifndef SEPARABLE_TRANSFORM_H
#define SEPARABLE_TRANSFORM_H

#include <string>
#include "sht.h"
#include "radial_transform.h"
#include "harmonic_coefficients.h"

namespace uber3d {


/**
  * class separable_transform
  * Base class for  all separable transforms
  */

class separable_transform
{
public:

    
    

protected:

    // Protected member functions
    //

    /**
     * Initialises a separable transform and allocate necessary memory
     * 
     */
    separable_transform(uber3d::sht * sht, uber3d::radial_transform *m_rt);
    
    /**
    * Performs the forward Spherical Harmonics Transform and 
    * stores the resulting Alm(r) in the internal almnr array.
    * \param  in_map Input map to transform
    */
    template <typename T1, typename T2>
    void forward_transform(uber3d::map<T1> &in_map, uber3d::harmonic_coefficients<T2> &out_coeff);
    
    /**
    * Performs the backward Spherical Harmonics Transform from
    * the Alm(r) elements stored in internal array.
    * \param  out_map Reconstructed map
    */
    template <typename T1, typename T2>
    void backward_transform(uber3d::harmonic_coefficients<T1> &in_coeff, uber3d::map<T2> &out_map);

  // Protected attributes
  //  

  // Spherical Harmonics Transform to apply on shells
  uber3d::sht * m_sht;
  // Radial transform to apply on lines of sight
  uber3d::radial_transform * m_rt;


};
} // end of package namespace

#endif // SEPARABLE_TRANSFORM_H
