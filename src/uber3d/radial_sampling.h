
#ifndef RADIAL_SAMPLING_H
#define RADIAL_SAMPLING_H

#include <string>
#include <map>
#include <H5Cpp.h>
#include "radial_transform.h"


namespace uber3d {
 
/**
 * Radial sampling factory class
 * The purpose of this class is to be able to create specific instances of 
 * radial_sampling from a keyword
 */
// class radial_sampling_factory {
//     typedef std::map<std::string, radial_sampling*(*)()> map_type;
// 
//     static radial_sampling* createInstance(std::string const& s) {
//         map_type::iterator it = getMap()->find(s);
//         if(it == getMap()->end())
//             return 0;
//         return it->second();
//     }
// 
// protected:
//     static map_type * getMap() {
//         // never delete'ed. (exist until program termination)
//         // because we can't guarantee correct destruction order 
//         if(!map) { map = new map_type; } 
//         return map; 
//     }
// 
// private:
//     static map_type * map;
// };
// 
// template<typename T> 
// radial_sampling * createT() { return new T; }
// 
// template<typename T>
// class DerivedRegister : radial_sampling_factory { 
//     DerivedRegister(std::string const& s) { 
//         getMap()->insert(std::make_pair(s, &createT<T>));
//     }
// };


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
  virtual long get_nsamp () = 0;

  /**
   * Builds a Spherical Bessel Transform for the this radial sampling scheme
   * \return uber3d::radial_transform
   */
  virtual uber3d::radial_transform build_sbt () = 0;


  /**
   * Builds a Laguerre transform for this radial sampling scheme
   * \return uber3d::radial_transform
   */
  virtual uber3d::radial_transform build_laguerre_transform () = 0;

};
} // end of package namespace

#endif // RADIAL_SAMPLING_H
