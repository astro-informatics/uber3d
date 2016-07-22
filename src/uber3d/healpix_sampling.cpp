#include <iostream>
// All healpix headers can safely be imported here
#include <healpix_base.h>
#include <pointing.h>

#include "healpix_sampling.h"


using namespace uber3d;

// Constructors/Destructors
//  
healpix_sampling::healpix_sampling(int Nside, healpix_sampling::healpix_ordering_scheme order) :nside(Nside), order(order)
{
    healpix = new Healpix_Base2(nside, static_cast<Healpix_Ordering_Scheme>(order), SET_NSIDE);
    
}


healpix_sampling::~healpix_sampling()
{
    delete healpix;
}


//  
// Methods
//
uint64_t healpix_sampling::get_index(double theta, double phi)
{
    return healpix->ang2pix(pointing(theta, phi));
}

uint64_t healpix_sampling::get_npix()
{
    return healpix->Npix();
}

void healpix_sampling::get_theta_phi(uint64_t pixel_index, double& theta, double& phi)
{
    pointing point = healpix->pix2ang(pixel_index);
    theta = point.theta;
    phi   = point.phi;
}


sht healpix_sampling::build_sht(long int lmax)
{

}


