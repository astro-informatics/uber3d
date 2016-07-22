
#ifndef SFB_COEFFICIENTS_H
#define SFB_COEFFICIENTS_H

#include <string>

namespace uber3d {


/**
  * class sfb_coefficients
  * 
  */

template<class T>
class sfb_coefficients
{
public:

  // Public attributes
  //  
    
  // Maximum number of angular multipoles
  long Lmax;
  // Rmax of the boundary condition for discrete sampling
  double Rmax;
  // Maximum number of K samples
  long Nmax;

  // Constructors/Destructors
  //  
  /**
   * Creates an empty set of SFB coefficients 
   */
   sfb_coefficients ()
  {
  }
  
  /**
   * Loads  a set of SFB coefficients from an HDF5 file
   * \param  filename HDF5 filename
   * \param  dset_name Name of the dataset storing the  SFB coefficients
   */
   sfb_coefficients (std::string filename, std::string dset_name)
  {
  }


  /**
   * Creates new set of SFB coefficients with given size
   * \param  Lmax Maximum L multipole
   * \param  Nmax Maximum number of K samples
   * \param  Rmax Maximum R radius
   */
   sfb_coefficients (long Lmax, long Nmax, double Rmax)
  {
  }


  /**
   * Exports the coefficients to an HDF5 file
   * \param  filename Name of the HDF5 file
   * 
   * \param  dest_name Dataset name to store the coefficients
   */
  void to_HDF5 (std::string filename, std::string dest_name)
  {
  }


  /**
   * Returns the scale  k_ln for specified l and n indices
   * \return double
   * \param  l angular multipole index
   * \param  n radial scale index
   */
  double get_k_scale (double l, long n)
  {
  }

//read and write almn () 

protected:

  // Protected attributes
  //  

  // Array storing the coefficients
  arr2<T> data;


};
} // end of package namespace

#endif // SFB_COEFFICIENTS_H
