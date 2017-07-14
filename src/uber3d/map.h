
#ifndef MAP_H
#define MAP_H

#include <string>
#include <cstring>
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
   map (std::string filename, std::string dataset_name){


    H5::H5File file(filename.c_str(), H5F_ACC_RDONLY);
    H5::DataSet dset = file.openDataSet(dataset_name);
    
    // Extracts meta data
    attr_t attr_data; 
    H5::Attribute att = dset.openAttribute("map");
        
    H5::StrType h5_string_type(H5::PredType::C_S1, 256);
    H5::CompType mtype( sizeof(attr_t) );
    mtype.insertMember("spherical_sampling", HOFFSET(attr_t, sph_samp), h5_string_type);
    mtype.insertMember("radial_sampling",    HOFFSET(attr_t, rad_samp), h5_string_type);
    att.read(mtype, &attr_data);
    
    // Allocate new radial and spherical sampling schemes
    // TODO: Use a proper object factory to allow the creation of the right objects
    r_samp   = radial_sampling::factory(std::string(attr_data.rad_samp));
    r_samp->from_HDF5(dset);
    sph_samp = spherical_sampling::factory(std::string(attr_data.sph_samp));
    sph_samp->from_HDF5(dset);
    
    // Loads the data
    H5::DataSpace dspace = dset.getSpace();
    hsize_t dims_out[2];
    int ndims = dspace.getSimpleExtentDims( dims_out, NULL);
    data.alloc(dims_out[0], dims_out[1]);
    dset.read(data[0], get_hdf_type());
    
    file.close();
       
    }

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
        
        // Adds attribute to store meta data
        attr_t attr_data; 
        std::strcpy(attr_data.sph_samp, sph_samp->get_name().c_str());
        std::strcpy(attr_data.rad_samp, r_samp->get_name().c_str());
        
        H5::StrType h5_string_type(H5::PredType::C_S1, 256);
        H5::CompType mtype( sizeof(attr_t) );
        mtype.insertMember("spherical_sampling", HOFFSET(attr_t, sph_samp), h5_string_type);
        mtype.insertMember("radial_sampling",    HOFFSET(attr_t, rad_samp), h5_string_type);
        
        // Defines dataspace
        const hsize_t attr_dims[1] = { 1 };
        H5::DataSpace attr_dataspace = H5::DataSpace(1, attr_dims);
        
        // Create attribute and add it to the dataset
        H5::Attribute att = dset.createAttribute("map", mtype, attr_dataspace);
        att.write(mtype, &attr_data);
        
        // Export data from sampling schemes to dataset
        r_samp->to_HDF5(dset);
        sph_samp->to_HDF5(dset);
        
        // All done
        file.close();
    }

  
  // Accessors 
  //
  
  /**
   * Returns the radial sampling
   */
   uber3d::radial_sampling& get_radial_sampling()
  { return *r_samp; }
  
  /**
   *  Returns the spherical sampling
   */
   uber3d::spherical_sampling& get_spherical_sampling()
  { return *sph_samp; }
  
  /*! Returns a pointer to the beginning of slice \a n. */
  template<typename T2> T *operator[] (T2 n) {return data[n];}
  
  /*! Returns a constant pointer to the beginning of slice \a n. */
  template<typename T2> const T *operator[] (T2 n) const {return data[n];}
  
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
  // Structure to store meta data about the map
  typedef struct attr_t{
      char rad_samp[256];
      char sph_samp[256];
  } attr_t;
  
  // Radial sampling scheme
  uber3d::radial_sampling *r_samp;
  // Spherical sampling scheme
  uber3d::spherical_sampling *sph_samp;

};
} // end of package namespace

#endif // MAP_H
