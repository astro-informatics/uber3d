cmake_minimum_required(VERSION 3.0)

# Adding customized cmake modules
list(APPEND CMAKE_MODULE_PATH  "${CMAKE_SOURCE_DIR}/cmake/Modules/")


add_subdirectory(src/c_utils)

add_subdirectory(src/libfftpack)

add_subdirectory(src/cxxsupport)

add_subdirectory(src/libsharp)

add_subdirectory(src/ssht)

add_subdirectory(src/Healpix_cxx)

add_subdirectory(src/uber3d)