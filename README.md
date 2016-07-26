
# Uber3D
**3D Fourier transforms and pixelizations for galaxy survey analyses.**

![alt tag](https://travis-ci.org/astro-informatics/uber3d.svg?branch=master)
![alt tag](http://img.shields.io/:license-gpl2-blue.svg?style=flat)

## Install

Use the command `mkdir build; cmake .. ; make`

**Dependencies**: cmake, HDF5

On **Mac OS** this can be achieved with `brew install cmake homebrew/science/hdf5`. This might require unlinking other installs of HDF5 (e.g. from anaconda).

## Test

Use the command `src/uber3d/uber_test`

## Contribute

To contribute to the code i.e. add a feature or correct a bug, first open an issue describing your proposed modifications, create a branch from master to work on this issue, and finally, once the feature is implemented, submit a pull request to merge your modification with master.

NOTE: master is a protected branch, you cannot push your modifications directly to this branch. You need to submit a pull request, which can only be accepted if the proposed modifications pass the Travis CI build  

## License

Copyright 2016 the authors. The code in this repository is released under the open-source GPL2 License. See the file LICENSE for more details.
