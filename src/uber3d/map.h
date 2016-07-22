
#ifndef MAP_H
#define MAP_H

#include <string>
#include <H5Cpp.h>

#include "arr.h"
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

  // Constructors/Destructors
  //  

  /**
   * Default constructor which allocates a new array to store data based on the
   * specified sampling schemes
   * \param  r_samp Specifies the radial sampling scheme
   * \param  sph_samp Specifies the spherical sampling scheme
   */
   map (uber3d::radial_sampling &rsamp, uber3d::spherical_sampling &sphsamp)
   {
    // Allocates new radial and spherical sampling objects
    r_samp = rsamp.copy();
    sph_samp = sphsamp.copy();
      
    // Allocates data array
    data.alloc(r_samp->get_nsamp(), sph_samp->get_nsamp());
    }

  /**
   * Constructs a new map object from the specified HDF5 dataset 
   * \param  filename Loads a map from an HDF5 file
   * \param  dataset_name Dataset name to use for export
   */
   map (std::string filename, std::string dataset_name){ }

  /**
   * Exports  the entire  map data to an HDF5 file
   * \param  filename File name of output HDF5 file
   * \param  dataset_name Dataset name to use for export
   */
  void to_HDF5 (std::string filename, std::string dataset_name){
        H5::H5File file(filename.c_str(), H5F_ACC_TRUNC);
        
        // Create dataspace to store the data
        hsize_t dims[2];
        dims[0] = r_samp->get_nsamp();
        dims[1] = sph_samp->get_nsamp();
        H5::DataSpace dspace(2, dims);

        // Create dataset with given name
        H5::DataSet dset = file.createDataSet(dataset_name, get_hdf_type(), dspace);
         
        // Write data to the dataset
        dset.write(data[0], get_hdf_type());
        
        // Export data from sampling schemes to dataset
        r_samp->to_HDF5(dset);
        
        // All done
        file.close();
    }

  
  // Accessors 
  //
  
  /**
   * Returns the radial sampling
   */
  const uber3d::radial_sampling& get_radial_sampling()
  { return *r_samp; }
  
  /**
   *  Returns the spherical sampling
   */
  const uber3d::spherical_sampling& get_spherical_sampling()
  { return *sph_samp; }

  
protected:

  // Protected attributes
  //  

  // 2D array storing the map as a series of spherical shells
  arr2<T> data;


private:
    
  // Private methods
  //
  H5::PredType get_hdf_type();

  // Private attributes
  //  

  // Radial sampling scheme
  uber3d::radial_sampling *r_samp;
  // Spherical sampling scheme
  uber3d::spherical_sampling *sph_samp;

};
} // end of package namespace

#endif // MAP_H
