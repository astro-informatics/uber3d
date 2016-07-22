#include "map.h"




// Specializations
//  
namespace uber3d{
    template<> H5::PredType map<float>::get_hdf_type()
    {
        return H5::PredType::NATIVE_FLOAT;
    }
    template<> H5::PredType map<double>::get_hdf_type()
    {
        return H5::PredType::NATIVE_DOUBLE;
    }
}


