
#ifndef RADIAL_SAMPLING_H
#define RADIAL_SAMPLING_H

#include <string>
#include <map>
#include <H5Cpp.h>
#include "radial_transform.h"

namespace uber3d {
 
    
/**
  * class radial_sampling
  * 
  */

/******************************* Abstract Class ****************************
radial_sampling does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class radial_sampling
{
public:
   
   // Virtual destructor
   virtual ~radial_sampling() {}
   
   //TODO: Improve sampling factory
   static radial_sampling *factory(std::string sampling_name);
   
   /**
    * Returns a newly allocated copy of the sampling scheme
    */
   virtual radial_sampling *copy() = 0;

   /**
    * Allocates the radial_sampling scheme from an HDF5 data set
    *   
    */
   virtual void from_HDF5(H5::DataSet dset) = 0;
   
   /**
    * Exports information about the radial sampling to HDF5 data set
    * 
    */
   virtual void to_HDF5(H5::DataSet dset) = 0;
   
  /**
   * Returns the radius for the  provided radial index
   * \return double
   * \param  ind Radial index
   */
  virtual double get_r (long ind) = 0;

  /**
   * Returns the number of radial samples
   * \return long
   */
  virtual uint64_t get_nsamp () = 0;
  
  
  /**
   * Returns the name of the sampling scheme
   * \return std::string
   */
   virtual std::string get_name () = 0;

  /**
   * Builds a Spherical Bessel Transform for the this radial sampling scheme
   * \return uber3d::radial_transform
   * \param lmax Maximum order of the spherical Bessel transform
   * \param kmax Maximum scale
   */
  virtual uber3d::radial_transform *build_sbt (long int lmax, double kmax) = 0;


  /**
   * Builds a Laguerre transform for this radial sampling scheme
   * \return uber3d::radial_transform
   */
  virtual uber3d::radial_transform *build_laguerre_transform () = 0;

};



} // end of package namespace

#endif // RADIAL_SAMPLING_H
