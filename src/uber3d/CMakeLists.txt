cmake_minimum_required(VERSION 3.0)

set(UBER3D_SRCS almn_cln_tools.cpp almn_fitsio.cpp cln_fitsio.cpp)

add_library(uber3d SHARED ${UBER3D_SRCS})
target_link_libraries(uber3d c_utils fftpack sharp cxxsupport )
target_include_directories(uber3d
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:c_utils,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:fftpack,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:sharp,INTERFACE_INCLUDE_DIRECTORIES>
    PRIVATE $<TARGET_PROPERTY:cxxsupport,INTERFACE_INCLUDE_DIRECTORIES>)
