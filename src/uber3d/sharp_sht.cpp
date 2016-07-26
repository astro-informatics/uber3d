#include "sharp_sht.h"
#include <sharp_cxx.h>

using namespace uber3d;


sharp_sht::sharp_sht()
{
    dsharpjob = new sharp_cxxjob<double>;
    fsharpjob = new sharp_cxxjob<float>;
}

sharp_sht::~sharp_sht()
{
    delete dsharpjob;
    delete fsharpjob;
}


void sharp_sht::set_healpix_geometry(long int nside)
{
    dsharpjob->set_Healpix_geometry(nside);
    fsharpjob->set_Healpix_geometry(nside);   
}

void sharp_sht::forward(const arr< double > &in_map, arr< dcomplex > &out_alm)
{
    dsharpjob->map2alm(in_map.begin(), out_alm.begin(), false);
}

void sharp_sht::backward(const arr< dcomplex > &in_alm, arr< double > &out_map)
{
    dsharpjob->alm2map(in_alm.begin(), out_map.begin(), false);
}
void sharp_sht::forward(const arr< float > &in_map, arr< fcomplex > &out_alm)
{
    fsharpjob->map2alm(in_map.begin(), out_alm.begin(), false);
}

void sharp_sht::backward(const arr< fcomplex > &in_alm, arr< float > &out_map)
{
    fsharpjob->alm2map(in_alm.begin(), out_map.begin(), false);
}
