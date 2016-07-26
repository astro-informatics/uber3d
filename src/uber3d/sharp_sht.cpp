#include "sharp_sht.h"
#include <sharp_cxx.h>

using namespace uber3d;


sharp_sht::sharp_sht()
{
    sharpjob = new sharp_cxxjob<double>;
}

sharp_sht::~sharp_sht()
{
    delete sharpjob;
}


void sharp_sht::set_healpix_geometry(long int nside)
{
    sharpjob->set_Healpix_geometry(nside);
    
}

void sharp_sht::forward(const arr< double > &in_map, arr< dcomplex > &out_alm)
{
    sharpjob->map2alm(in_map.begin(), out_alm.begin(), false);
}

void sharp_sht::backward(const arr< dcomplex > &in_alm, arr< double > &out_map)
{
    sharpjob->alm2map(in_alm.begin(), out_map.begin(), false);
}
