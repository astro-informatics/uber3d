cmake_minimum_required(VERSION 3.0)

# Adding customized cmake modules
list(APPEND CMAKE_MODULE_PATH  "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Define default options
option(FITS_SUPPORT "Enable FITSIO support" OFF)

set(CMAKE_C_FLAGS   "-std=c11")
set(CMAKE_CXX_FLAGS  "-std=c++11")

add_subdirectory(src/c_utils)

add_subdirectory(src/libfftpack)

add_subdirectory(src/cxxsupport)

add_subdirectory(src/libsharp)

add_subdirectory(src/Healpix_cxx)

add_subdirectory(src/uber3d)
