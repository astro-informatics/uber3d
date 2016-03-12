

#include <almn.h>


almn map2almn<T, AngularMap, RadialMap>(ThreeDimMap<T, AngularMap, RadialMap> map){

  int numShells = map.radialMap_.getMapSize();
  arr<Alm<T> almr(numShells);

  for (size_t i = 0; i < numShells; i++) {
    almr
    almr(i) = map.angularMap_.transform(map.getShell(i));
  }

  int numSHcoefs = map.angularMap_.getMapSize();
  for (size_t i = 0; i < numSHcoefs; i++) {
    arr<double> radialNodes(numShells);
    for (size_t j = 0; i < numShells; i++) {
      radialNodes(j) = almr(j)(i);
    }
    arr<double> radialCoefs = map.angularMap_.transform(radialNodes);
  }

}
