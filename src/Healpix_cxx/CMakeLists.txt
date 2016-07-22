cmake_minimum_required(VERSION 3.0)

project(healpix)

set(HEALPIX_SRCS 
  powspec.cc alm.cc alm_powspec_tools.cc
  healpix_tables.cc healpix_base.cc healpix_map.cc moc_query.cc
)

if(FITS_SUPPORT)
    set(HEALPIX_SRCS ${HEALPIX_SRCS} alm_fitsio.cc powspec_fitsio.cc healpix_map_fitsio.cc moc_fitsio.cc healpix_data_io.cc)
endif(FITS_SUPPORT)

add_library(healpix SHARED ${HEALPIX_SRCS})

target_link_libraries(healpix cxxsupport c_utils fftpack sharp)
target_include_directories(healpix 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:c_utils,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:fftpack,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:cxxsupport,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:sharp,INTERFACE_INCLUDE_DIRECTORIES>
    )