/*! Generic class for Radial Map (Bessel, Laguerre, etc)
  i.e. an array representing a 1D pixelized radial line of sight
  */
class RadialMap {
private:
  int nmax_;
  int mapSize_;
  double Rmax_;
public:
  int getMapSize(){ return mapSize_; }
};

/*!
  Wrapper for Spherical Laguerre sampling
  */
class SphereLaguerreMap : RadialMap {

  SphereLaguerreMap SphereLaguerreMap(double Rmax, int nmax)
    : Rmax_(Rmax), nmax_(nmax)){
    //TODO: compute tau from Rmax and nmax
  }

};

/*!
  Wrapper for Spherical Bessel sampling
  */
class SphereBesselMap : RadialMap {

  double Kmax_;
  int ell_;

  SphereBesselMap SphereBesselMap(double Rmax, double Kmax, int ell)
    : Rmax_(Rmax), Kmax_(Kmax), ell_(ell){
    //TODO: compute Nmax from ell and Kmax
  }

};
