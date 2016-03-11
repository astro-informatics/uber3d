/*! Generic class for Angular Map (Healpix, MW, etc)
  i.e. an array representing a 2D pixelized map
  */
class AngularMap {
private:
  int lmax_;
  int mapSize_;
public:
  int getMapSize(){ return mapSize_; }
  int index(int l, int m);
  Alm sphere2alm();
};

/*!
  Wrapper for MW pixelized 2D map
  */
class MWmap : AngularMap {

  MWmap MWmap(int lmax): lmax_(lmax) {
    mapSize_ = lmax*lmax;
  }

  int harmonicIndex(int l, int m){
    return l*l + l + m;
  }

  Alm sphere2alm(){
    // TODO
  }

};

/*!
  Wrapper for Healpix pixelized 2D map
  */
class HPXmap : AngularMap {

  int nside_;

  HPXmap HPXmap(int nside, int lmax): nside_(nside), lmax_(lmax) {
    mapSize_ = 12*nside_*nside_;
  }

  int harmonicIndex(int l, int m) {
    // TODO
  }

  Alm sphere2alm(){
    // TODO
  }

};
