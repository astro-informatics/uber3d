/*
/*! \file almn.cc
 *  Class for storing spherical-Bessel harmonic coefficients.
 */

#include "almn.h"

using namespace std;

//static
tsize Almn_Base::Num_Almns (int l, int m, int n)
  {
    //planck_assert(m<=l,"mmax must not be larger than lmax");
    return (((m+1)*(m+2))/2 + (m+1)*(l-m))*n;
  }

void Almn_Base::swap (Almn_Base &other)
  {
  std::swap(lmax, other.lmax);
  std::swap(mmax, other.mmax);
  std::swap(nmax, other.nmax);
  std::swap(tval, other.tval);
  std::swap(tval2, other.tval2);
  }
