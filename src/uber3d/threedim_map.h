class ThreeDimMap<T, AngularMap, RadialMap> {

  arr<AngularMap> shells_;
  AngularMap angularMap_;
  RadialMap radialMap_;

  /*! Constructor */
  ThreeDimMap<T, AngularMap, RadialMap> ThreeDimMap(T initialValue, AngularMap angularMap, RadialMap radialMap)
  : angularMap_(angularMap), radialMap_(radialMap), shells_(radialMap_.getMapSize())
  {

  }

  /*! Returns a sphere */
  AngularMap getShell(int ishell)
  {
    return shells_(ishell);
  }

  /*! Returns a sphere */
  const AngularMap getShell(int ishell)
  {
    return shells_(ishell);
  }

};
