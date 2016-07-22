/*! \file almn.h
 *  Class for storing spherical-Bessel harmonic coefficients.
 */

#ifndef UBER3D_ALMN_H
#define UBER3D_ALMN_H

#include "arr.h"

/*! Base class for calculating the storage layout of spherical harmonic
    coefficients. */
class Almn_Base
  {
  protected:
    int lmax, mmax, nmax, tval;

  public:
    /*! Returns the total number of coefficients for maximum quantum numbers
        \a l and \a m and \a n. */
    static tsize Num_Almns (int l, int m, int n);

    /*! Constructs an Alm_Base object with given \a lmax and \a mmax and \a nmax. */
    Almn_Base (int lmax_=0, int mmax_=0, int=nmax_=0)
      : lmax(lmax_), mmax(mmax_), nmax(nmax_), tval(2*lmax+1), tval2(2.*mmax+1.) {}

    /*! Changes the object's maximum quantum numbers to \a lmax and \a mmax and \a nmax. */
    void Set (int lmax_, int mmax_, int nmax_)
      {
          lmax=lmax_;
          mmax=mmax_;
          nmax=nmax_;
          tval=2*lmax+1;
          tval2=2*mmax+1;
      }

    /*! Returns the maximum \a l */
    int Lmax() const { return lmax; }
    /*! Returns the maximum \a m */
    int Mmax() const { return mmax; }
    /*! Returns the maximum \a n */
    int Nmax() const { return nmax; }
      
    /*! Returns an array index for a given n, from which the index of a_lmn
        can be obtained by adding l and ,. */
    int index_l0 (int n) const
      { return ((n*(tval2-n))>>1); }

    /*! Returns an array index for a given m, from which the index of a_lmn
       can be obtained by adding l. */
    int index_l1 (int m, int n) const
      { return (index_l0(n)+(m*(tval-m))>>1); }
      
    /*! Returns the array index of the specified coefficient. */
    int index (int l, int m, int n) const
      { return index_l1(m) + l; }

    /*! Returns \a true, if both objects have the same \a lmax and \a mmax,
        else  \a false. */
    bool conformable (const Almn_Base &other) const
      { return ((lmax==other.lmax) && (mmax==other.mmax) && (nmax==other.nmax)); }

    /*! Swaps the contents of two Alm_Base objects. */
    void swap (Almn_Base &other);
  };

/*! Class for storing spherical-Bessel harmonic coefficients. */
template<typename T> class Almn: public Almn_Base
  {
  private:
    arr<T> almn;

  public:
    /*! Constructs an Alm object with given \a lmax and \a mmax and \a nmax. */
    Almn (int lmax_=0, int mmax_=0, int nmax_=0)
      : Almn_Base(lmax_,mmax_,nmax_), almn (Num_Almns(lmax,mmax,nmax)) {}

    /*! Deletes the old coefficients and allocates storage according to
        \a lmax and \a mmax and \a nmax. */
    void Set (int lmax_, int mmax_, int nmax_)
      {
      Almn_Base::Set(lmax_, mmax_, nmax_);
      almn.alloc(Num_Alms(lmax,mmax,nmax));
      }

    /*! Deallocates the old coefficients and uses the content of \a data
        for storage. \a data is deallocated during the call. */
    void Set (arr<T> &data, int lmax_, int mmax_, int nmax_)
      {
      //planck_assert (Num_Almns(lmax_,mmax_,nmax_)==data.size(),"wrong array size");//not yet implemented
      Almn_Base::Set(lmax_, mmax_, nmax_);
      almn.transfer(data);
      }

    /*! Sets all coefficients to zero. */
    void SetToZero ()
      { almn.fill (0); }

    /*! Multiplies all coefficients by \a factor. */
    template<typename T2> void Scale (const T2 &factor)
      {
          for (tsize m=0; m<alm.size(); ++m) alm[m]*=factor;
      }
    /*! \a a(l,m,n) *= \a factor[l] for all \a l,m,n. */
    template<typename T2> void ScaleL (const arr<T2> &factor)
      {
      //planck_assert(factor.size()>tsize(lmax),"alm.ScaleL: factor array too short");//not yet implemented
      for (int n=0; n<=nmax; ++n)
          for (int m=n; m<=mmax; ++m)
              for (int l=m; l<=lmax; ++l)
                  operator()(l,m,n)*=factor[l];
      }
    /*! \a a(l,m,n) *= \a factor[m] for all \a l,m,n. */
    template<typename T2> void ScaleM (const arr<T2> &factor)
      {
      //planck_assert(factor.size()>tsize(mmax),"alm.ScaleM: factor array too short");
      for (int n=0; n<=nmax; ++n)
          for (int m=n; m<=mmax; ++m)
              for (int l=m; l<=lmax; ++l)
                  operator()(l,m,n)*=factor[m];
      }
    /*! \a a(l,m,n) *= \a factor[n] for all \a l,m,n. */
    template<typename T2> void ScaleN (const arr<T2> &factor)
      {
      //planck_assert(factor.size()>tsize(mmax),"alm.ScaleM: factor array too short");
      for (int n=0; n<=nmax; ++n)
         for (int m=n; m<=mmax; ++m)
              for (int l=m; l<=lmax; ++l)
                 operator()(l,m,n)*=factor[n];
      }

    /*! Adds \a num to a_00. */
    template<typename T2> void Add (const T2 &num)
      { alm[0]+=num; }

    /*! Returns a reference to the specified coefficient. */
    T &operator() (int l, int m, int n)
      { return almn[index(l,m,n)]; }
    /*! Returns a constant reference to the specified coefficient. */
    const T &operator() (int l, int m) const
      { return almn[index(l,m,n)]; }

    /*! Returns a pointer for a given n, from which the address of a_lmn
       can be obtained by adding l and m. */
      T *nstart (int n)
      { return &almn[index_l0(n)]; }
      /*! Returns a pointer for a given m, from which the address of a_lm
       can be obtained by adding l. */
      const T *nstart (int n) const
      { return &almn[index_l0(n)]; }
      
    /*! Returns a pointer for a given m, from which the address of a_lmn
        can be obtained by adding l. */
    T *mstart (int m, int n)
      { return &almn[index_l1(m, n)]; }
    /*! Returns a pointer for a given m, from which the address of a_lm
        can be obtained by adding l. */
    const T *mstart (int m, int n) const
      { return &almn[index_l1(m, n)]; }

    /*! Returns a constant reference to the a_lmn data. */
    const arr<T> &Almns () const { return almn; }

    /*! Swaps the contents of two Alm objects. */
    void swap (Almn &other)
      {
      Almn_Base::swap(other);
      almn.swap(other.almn);
      }

    /*! Adds all coefficients from \a other to the own coefficients. */
    void Add (const Almn &other)
      {
      //planck_assert (conformable(other), "A_lm are not conformable");//not yet implemented
      for (tsize m=0; m<almn.size(); ++m)
        almn[m] += other.almn[m];
      }
  };

#endif
