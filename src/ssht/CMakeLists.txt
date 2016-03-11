cmake_minimum_required(VERSION 3.0)

find_package(FFTW  REQUIRED)
include_directories(${FFTW_INCLUDE_DIR})   
link_directories(${FFTW_LIBRARY_DIR})

set(SSHT_SRCS ssht_sampling.c ssht_dl.c ssht_core.c ssht_adjoint.c)

add_library(ssht SHARED ${SSHT_SRCS})
target_link_libraries(ssht ${FFTW_LIBRARIES})
target_include_directories(ssht INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

     