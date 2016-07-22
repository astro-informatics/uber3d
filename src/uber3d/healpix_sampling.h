
#ifndef HEALPIX_SAMPLING_H
#define HEALPIX_SAMPLING_H
#include <string>

#include "spherical_sampling.h"

#define HEALPIX_SAMPLING_NAME "healpix"

// Declares outside dependencies to avoid having to include the header files here
// Instead the healpix header files are included in healpix_sampling.cpp
// This is to try to keep the uber3d header clean and not specific to one
// library
template<typename T> class T_Healpix_Base; 
typedef T_Healpix_Base<int64_t> Healpix_Base2;


namespace uber3d {

/**
  * class healpix_sampling
  * 
  */
class healpix_sampling : public spherical_sampling
{
    
public:
    
  // Redefine the healpix ordering scheme for uber3d
  enum healpix_ordering_scheme{ RING, /*!< RING scheme   */
                                NEST  /*!< NESTED scheme */
                                };
 
  // Constructors/Destructors
  //
  // Empty constructor
  healpix_sampling();
  
                                
  /**
   * Creates an HEALPix spherical sampling scheme.
   * 
   * \param Nside HEALPix nside parameter
   * \param order HEALPix ordering
   */
   healpix_sampling(int Nside, healpix_ordering_scheme order);
   
  /**
   * Creates an HEALPix spherical sampling scheme using RING order by default
   * 
   * \param Nside HEALPix nside parameter
   */
   healpix_sampling(int Nside) : healpix_sampling(Nside, healpix_ordering_scheme::RING) { }
   
   /**
    * Copy constructor
    * 
    */
   healpix_sampling(const healpix_sampling &src) : healpix_sampling(src.nside, src.order) {}
   
   /**
    * Destructor
    */
   ~healpix_sampling();
   
   /**
    * Returns a newly allocated deep copy of the sampling scheme
    */
   healpix_sampling *copy(){
       healpix_sampling *out = new healpix_sampling(*this);
       return out;
   }
    
   /**
    * Allocates the radial_sampling scheme from an HDF5 data set
    *   
    */
    void from_HDF5(H5::DataSet dset);
   
   /**
    * Exports information about the radial sampling to HDF5 data set
    * 
    */
    void to_HDF5(H5::DataSet dset);
   
    
    
  /**
   * Returns the  pair (theta, phi) for the pixel of specified index
   * \param  pixel_index Pixel index
   * \param  theta       Output theta
   * \param  phi         Output phi
   */
  void get_theta_phi (uint64_t pixel_index, double &theta, double &phi);

  /**
   * Returns the pixel index corresponding to specified coordinates
   * \return long
   * \param  theta
   * \param  phi
   */
   uint64_t get_index (double theta, double phi);


  /**
   * Returns the number of pixels used in this sampling scheme
   * \return long
   */
   uint64_t get_nsamp ();

   
  /**
   * Returns the name of the sampling scheme
   * \return std::string
   */
   std::string get_name (){
      return std::string(HEALPIX_SAMPLING_NAME);
   }

  /**
   * Builds a new SHT transform for this sampling scheme
   * \return uber3d::sht
   * \param  lmax Maximum angular multipole
   */
   uber3d::sht build_sht (long lmax);

private:

  // Private attributes
  //  

  typedef struct attr_t{
      long Nside;
      long Order;
  } attr_t;
    
    
  // HEALPix nside parameter
  int nside;
  
  // HEALPix ring ordering
  healpix_ordering_scheme order;
  
  // HEALPix base structure
  Healpix_Base2 *healpix;
  
};
} // end of package namespace

#endif // HEALPIX_SAMPLING_H
