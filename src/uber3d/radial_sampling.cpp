#include "radial_sampling.h"
#include "bessel_sampling.h"

uber3d::radial_sampling * uber3d::radial_sampling::factory(std::string sampling_name)
{
    if(sampling_name == std::string(BESSEL_SAMPLING_NAME)){
        return new bessel_sampling;
    }else{
        std::cout << "Unknown sampling scheme" << std::endl; 
        return NULL;
    }
}

