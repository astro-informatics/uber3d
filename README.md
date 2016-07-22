
# Uber3D
**3D Fourier transforms for galaxy survey analyses.**

![alt tag](https://travis-ci.org/astro-informatics/uber3d.svg?branch=master)
![alt tag](http://img.shields.io/:license-gpl2-blue.svg?style=flat)

## Install

The standard build command is

mkdir build; brew install cmake; cmake .. ; make

Dependencies: HDF5

brew install homebrew/science/hdf5

Common issues and how to fix them:
- unlink any other HDF5 install (e.g. from anaconda)
- set GCC compiler with "CC=gcc cmake .."

## License

Copyright 2016 the authors. The code in this repository is released under the open-source GPL2 License. See the file LICENSE for more details.
