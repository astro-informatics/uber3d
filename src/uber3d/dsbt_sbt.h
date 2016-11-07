
#ifndef DSBT_SBT_H
#define DSBT_SBT_H

#include "radial_transform.h"


// Forward declaration of FastDSBT to avoid having to include the header here
class FastDSBT;

namespace uber3d{

    
/**
  * class dsbt_sbt
  * 
  * Implements a radial spherical bessel transform based on libdsbt
  * 
  */
class dsbt_sbt: public radial_transform
{
  
public:  
  // Constructor/Destructor
  //
   dsbt_sbt(long int Lmax, long int Nmax, double Rmax); 
   
   ~dsbt_sbt();
    
  /**
   * Computes forward radial transform along a line of sight
   * \param  in_los Input line of sight
   * \param  out_coeff Output coefficients
   */
   void forward (const arr<float> &in_los, arr<float> &out_coeff){}
   void forward (const arr<double> &in_los, arr<double> &out_coeff);

  /**
   * Computes backward transform from coefficients to line of sight
   * \param  in_coeff Input coefficients
   * \param  out_los Output line of sight
   */
   void backward (const arr<float> &in_coeff, arr<float> &out_los){}
   void backward (const arr<double> &in_coeff, arr<double> &out_los);

private:

   FastDSBT *dsbt;

   // Radial boundary value 
   double r_max;
   uint64_t l_max;
   uint64_t n_max;

};
} // end of package namespace

#endif // DSBT_SBT_H
