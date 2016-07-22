cmake_minimum_required(VERSION 3.0)

project(cxxsupport)


set(CXXSUPPORT_SRCS 
  error_handling.cc string_utils.cc paramfile.cc walltimer.cc ls_image.cc
  rotmatrix.cc trafos.cc wigner.cc pointing.cc geom_utils.cc
  announce.cc
)

# Try to find FITS library, if fails, disable FITS_SUPPORT
if(FITS_SUPPORT)
    find_package(cfitsio REQUIRED)
    if(NOT CFITSIO_FOUND)
        set(FITS_SUPPORT OFF)
        message("CFITSIO library not found, disabling fits support")
    endif()
endif(FITS_SUPPORT)
        
if(FITS_SUPPORT)
    include_directories(${CFITSIO_INCLUDE_DIR})   
    link_directories(${CFITSIO_LIBRARY_DIR})
    set(CXXSUPPORT_SRCS ${CXXSUPPORT_SRCS} fitshandle.cc)
endif(FITS_SUPPORT)

add_library(cxxsupport SHARED ${CXXSUPPORT_SRCS})

target_link_libraries(cxxsupport ${CFITSIO_LIBRARY} c_utils fftpack)
target_include_directories(cxxsupport 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:c_utils,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:fftpack,INTERFACE_INCLUDE_DIRECTORIES>)