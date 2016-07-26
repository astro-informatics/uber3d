#include <iostream>
// All healpix headers can safely be imported here
#include <healpix_base.h>
#include <pointing.h>

#include "healpix_sampling.h"
#include "sharp_sht.h"

using namespace uber3d;

// Constructors/Destructors
//  

healpix_sampling::healpix_sampling()
{
    nside =0;
    healpix = new Healpix_Base2();
}


healpix_sampling::healpix_sampling(int Nside, healpix_sampling::healpix_ordering_scheme order) :nside(Nside), order(order)
{
    healpix = new Healpix_Base2(nside, static_cast<Healpix_Ordering_Scheme>(order), SET_NSIDE);
    
}


healpix_sampling::~healpix_sampling()
{
    delete healpix;
}



void healpix_sampling::from_HDF5(H5::DataSet dset)
{
    attr_t attr_data; 
        
    // Create attribute type
    H5::CompType mtype( sizeof(attr_t) );
    mtype.insertMember( "nside",           HOFFSET(attr_t, Nside), H5::PredType::NATIVE_LONG);
    mtype.insertMember( "ordering_scheme", HOFFSET(attr_t, Order), H5::PredType::NATIVE_LONG);
    
    // TODO: Raise an error if attributes not found
    H5::Attribute att = dset.openAttribute(HEALPIX_SAMPLING_NAME);
    att.read(mtype, &attr_data);

    // Update sampling scheme based on values read in the file
    nside = attr_data.Nside;
    order = static_cast<healpix_ordering_scheme>(attr_data.Order);
    healpix->SetNside(nside, static_cast<Healpix_Ordering_Scheme>(order));
}


void healpix_sampling::to_HDF5(H5::DataSet dset)
{
   // Create the data to export
    attr_t attr_data;
    attr_data.Nside = nside;
    attr_data.Order = order;
    
    // Create attribute type
    H5::CompType mtype( sizeof(attr_t) );
    mtype.insertMember( "nside",           HOFFSET(attr_t, Nside), H5::PredType::NATIVE_LONG);
    mtype.insertMember( "ordering_scheme", HOFFSET(attr_t, Order), H5::PredType::NATIVE_LONG);
    
    // Defines dataspace
    const hsize_t attr_dims[1] = { 1 };
    H5::DataSpace attr_dataspace = H5::DataSpace (1, attr_dims);
    
    // Create attribute and add it to the dataset
    H5::Attribute att = dset.createAttribute(HEALPIX_SAMPLING_NAME, mtype, attr_dataspace);
    att.write(mtype, &attr_data);
}


//  
// Methods
//
uint64_t healpix_sampling::get_index(double theta, double phi)
{
    return healpix->ang2pix(pointing(theta, phi));
}

uint64_t healpix_sampling::get_nsamp()
{
    return healpix->Npix();
}

void healpix_sampling::get_theta_phi(uint64_t pixel_index, double& theta, double& phi)
{
    pointing point = healpix->pix2ang(pixel_index);
    theta = point.theta;
    phi   = point.phi;
}

sht *healpix_sampling::build_sht(long int lmax)
{
    sharp_sht * sharp = new sharp_sht(lmax, lmax);
    sharp->set_healpix_geometry(healpix->Nside());
    return sharp;
}


