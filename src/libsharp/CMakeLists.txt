cmake_minimum_required(VERSION 3.0)

project(libsharp)

set(LIBSHARP_SRCS sharp_ylmgen_c.c sharp.c sharp_announce.c 
		  sharp_geomhelpers.c sharp_almhelpers.c sharp_core.c sharp_mpi.c)


add_library(sharp SHARED ${LIBSHARP_SRCS})
target_link_libraries(sharp c_utils fftpack)
target_include_directories(sharp 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:c_utils,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:fftpack,INTERFACE_INCLUDE_DIRECTORIES>)
     