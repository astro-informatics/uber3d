cmake_minimum_required(VERSION 3.0)

project(fftpack)

set(FFTPACK_SRCS fftpack.c bluestein.c ls_fft.c)


add_library(fftpack SHARED ${FFTPACK_SRCS})
target_include_directories(fftpack 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:c_utils,INTERFACE_INCLUDE_DIRECTORIES>)


