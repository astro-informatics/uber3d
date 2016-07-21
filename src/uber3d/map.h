
#ifndef MAP_H
#define MAP_H

#include <string>
#include "radial_sampling.h"
#include "spherical_sampling.h"


namespace uber3d {


/**
  * class map
  * 
  */

template<typename T>
class map
{
public:

  // Public attributes
  //  



  // Constructors/Destructors
  //  

  /**
   * Default constructor which allocates a new array to store the data based on the
   * specified sampling schemes
   * \param  r_samp Specifies the radial sampling scheme
   * \param  sph_samp Specifies the spherical sampling scheme
   */
   map (uber3d::radial_sampling r_samp, uber3d::spherical_sampling sph_samp)
  {
  }


  /**
   * Constructs a new map object from the specified HDF5 dataset 
   * \param  filename Loads a map from an HDF5 file
   * \param  dataset_name Dataset name to use for export
   */
   map (std::string filename, std::string dataset_name)
  {
  }


  /**
   * Exports  the entire  map data to an HDF5 file
   * \param  filename File name of output HDF5 file
   * \param  dataset_name Dataset name to use for export
   */
  void to_HDF5 (std::string filename, std::string dataset_name)
  {
  }


  /**
   * Returns the radius corresponding to given radial index
   * \return double
   * \param  ind_r Radial index
   */
  double get_r (long ind_r)
  {
  }


  /**
   * Returns a couple (theta, phi) for the corresponding spherical pixel index
   * \param  ind_sph Spherical pixel index
   */
  void get_theta_phi (long ind_sph)
  {
  }

protected:

  // Protected attributes
  //  

  // 2D array storing the map as a series of spherical shells
  arr2<T> data;


private:


  // Private attributes
  //  

  // Radial sampling scheme
  uber3d::radial_sampling r_samp;
  // Spherical sampling scheme
  uber3d::spherical_sampling sph_samp;


};
} // end of package namespace

#endif // MAP_H
