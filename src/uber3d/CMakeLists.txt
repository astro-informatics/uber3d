cmake_minimum_required(VERSION 3.0)

find_package(HDF5 COMPONENTS CXX REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})                                       
link_directories(${HDF5_LIBRARY_DIR})     

add_executable(uber3d main.cpp error_handling.cc healpix_sampling.cpp map.cpp bessel_sampling.cpp)
