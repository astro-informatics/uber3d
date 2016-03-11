cmake_minimum_required(VERSION 3.0)

project(cxxsupport)

set(CXXSUPPORT_SRCS 
  error_handling.cc string_utils.cc paramfile.cc walltimer.cc ls_image.cc
  rotmatrix.cc trafos.cc wigner.cc pointing.cc geom_utils.cc
  fitshandle.cc announce.cc
)

add_library(cxxsupport SHARED ${CXXSUPPORT_SRCS})
target_include_directories(cxxsupport 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:c_utils,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:fftpack,INTERFACE_INCLUDE_DIRECTORIES>)