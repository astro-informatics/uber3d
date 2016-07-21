
#include "map.h"


int main (int argc, const char **argv){
    
    uber3d::map<double> my_map("3dmap.hdf","map_in");
    
    my_map.to_HDF5("3dmap.hdf", "map_out");
    
}