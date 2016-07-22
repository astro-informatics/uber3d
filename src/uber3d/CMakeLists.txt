cmake_minimum_required(VERSION 3.0)

find_package(HDF5 COMPONENTS CXX REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})                                       
link_directories(${HDF5_LIBRARY_DIR})     

set(UBER3D_SRCS error_handling.cc healpix_sampling.cpp map.cpp bessel_sampling.cpp radial_sampling.cpp spherical_sampling.cpp)

add_library(uber3d SHARED ${UBER3D_SRCS})
target_link_libraries(uber3d c_utils fftpack sharp cxxsupport healpix ${HDF5_CXX_LIBRARIES})
target_include_directories(uber3d
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:c_utils,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:fftpack,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:sharp,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:cxxsupport,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:healpix,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(uber_test main.cpp)
target_link_libraries(uber_test uber3d)
