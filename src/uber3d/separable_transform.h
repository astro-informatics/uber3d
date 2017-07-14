
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

    // TO REMOVE
    separable_transform(){
    }
    
    /**
     * Initialises a separable transform and allocate necessary memory
     * 
     */
    separable_transform(uber3d::sht * spherical_transform, uber3d::radial_transform *radial_transform, long n_r, long n_alm){
            m_rt = radial_transform;
            m_sht = spherical_transform;

            // Initialise data array required to perform the transform
            N_r = n_r;
            N_alm = n_alm;

            tmp_coeff.alloc(n_r, n_alm);
    }

    /**
    * Performs the forward Spherical Harmonics Transform and 
    * stores the resulting Alm(r) in the internal almnr array.
    * \param  in_map Input map to transform
    */
    template <typename T1, typename T2>
    void forward_transform(uber3d::map<T1> &in_map, uber3d::harmonic_coefficients<T2> &out_coeff){

        // TODO: Add some MPI parallelisation here

        // Performs the spherical harmonics transform
    //    for(long i=0; i < N_r; i++){
         //   m_sht->forward(in_map[i], tmp_coeff[i]);
  //      }

        // Performs the radial transform
 //       for(long i=0; i < N_alm; i++){
 //           m_rt->forward(tmp_coeff[i], out_coeff[i]);
//        }
    }

    /**
    * Performs the backward Spherical Harmonics Transform from
    * the Alm(r) elements stored in internal array.
    * \param  out_map Reconstructed map
    */
    template <typename T1, typename T2>
    void backward_transform(uber3d::harmonic_coefficients<T1> &in_coeff, uber3d::map<T2> &out_map){

        // Performs the inverse  radial transform
  //      for(long i=0; i < N_alm; i++){
  //          m_rt->backward(tmp_coeff[i], out_coeff[i]);
  //      }
                
        // Performs the inverse spherical harmonics transform
 //       for(long i=0; i < N_r; i++){
   //         m_sht->backward(in_map[i], tmp_coeff[i]);
 //       }
    }

  // Protected attributes
  //  

  // Spherical Harmonics Transform to apply on shells
  uber3d::sht * m_sht;
  
  // Radial transform to apply on lines of sight
  uber3d::radial_transform * m_rt;
  
  arr2<double> tmp_coeff;
  
  // Number of radial shells to transform
  long N_r;
  
  // Number of harmonic coefficients  
  long N_alm;
};
} // end of package namespace

#endif // SEPARABLE_TRANSFORM_H
