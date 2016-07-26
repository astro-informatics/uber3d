#include "dsbt_sbt.h"
#include <fastDSBT.h>

using namespace uber3d;

dsbt_sbt::dsbt_sbt(long int Lmax, long int Nmax, double Rmax): 
r_max(Rmax), l_max(Lmax), n_max(Nmax)
{
    // Creates a new instance of FastDSBT
    dsbt = new FastDSBT(Nmax, Lmax, "qlnTable.bin");
}


dsbt_sbt::~dsbt_sbt()
{
    delete dsbt;
}


void dsbt_sbt::forward(const arr< double >& in_los, arr< double >& out_coeff)
{
    // Loop over l orders
    for(uint64_t l=0; l < l_max; l++){
        dsbt->computeDirectTransform(l, 0, r_max, in_los.begin(), out_coeff[l]);
    }
}


void dsbt_sbt::backward(const arr< double >& in_coeff, arr< double >& out_los)
{
    // Loop over l orders
    for(uint64_t l=0; l < l_max; l++){
        dsbt->computeInverseTransform(l, 0, r_max, in_coeff[l], out_los[l]);
    }
}
