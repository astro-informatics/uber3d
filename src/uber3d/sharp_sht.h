#ifndef SHARP_SHT_H
#define SHARP_SHT_H

#include "sht.h"

// Forward declaration to avoid having to include libsharp
// headers 
template<typename T> class sharp_cxxjob;

namespace uber3d {
    
    
/**
 * Class sharp_sht providing an implementaion of an sht 
 * based on the libsharp library
 */

class sharp_sht : public sht
{
    
public:
    
   // Constructor
   //
   sharp_sht();
    
    // Destructor
    //
    ~sharp_sht();
    
   /**
    * Initializes libsharp to process healpix geometries
    * 
    */
   void set_healpix_geometry(long nside);
    
   /**
   * Forward SHT transform
   * \param  in_map Input shell
   * \param  out_alm output spherical harmonic coefficients
   */
   void forward (const arr<double> &in_map, arr<dcomplex> &out_alm);


  /**
   * Backward spherical harmonics coefficients
   * \param  in_alm Input spherical harmonics coefficients
   * \param  out_map Ouput spherical shell
   */
   void backward (const  arr<dcomplex> &in_alm, arr<double> &out_map);
    
private:
    
    // Private members
    sharp_cxxjob<double> *sharpjob;
    
};

} // end of package namespace

#endif

