#include "spherical_sampling.h"
#include "healpix_sampling.h"

uber3d::spherical_sampling * uber3d::spherical_sampling::factory(std::string sampling_name)
{
    if(sampling_name == std::string(HEALPIX_SAMPLING_NAME)){
        return new healpix_sampling;
    }else{
        std::cout << "Unknown sampling scheme" << std::endl; 
        return NULL;
    }
}

