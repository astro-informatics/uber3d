
#include "map.h"
#include "sfb_coefficients.h"
#include "sfb_transform.h"

int main (int argc, const char **argv){
    
    
    // Loads a map from an HDF5 dataset
    uber3d::map<double> my_map("3dmap.hdf","map_in");
    
    // Creates a new empty set of almn coefficients
    uber3d::sfb_coefficients<double> almn;
    
    // Creates a new SFB transform
    long lmax = 100;
    long nmax = 100;
    uber3d::sfb_transform transform(my_map.get_radial_sampling(), my_map.get_spherical_sampling(), lmax, nmax);
    
    // Apply the transform
    transform.foward(my_map, almn);
    
    // Saves the computed coefficients
    almn.to_HDF5("3dmap.hdf", "almn_out");
    
}