cmake_minimum_required(VERSION 3.0)

project(dsbt)

find_package(Boost REQUIRED COMPONENTS math_c99)
include_directories(${Boost_INCLUDE_DIRS}) 

set(DSBT_SRCS fastDSBT.cpp)

add_library(dsbt SHARED ${DSBT_SRCS})
target_link_libraries(dsbt ${Boost_LIBRARIES})
target_include_directories(dsbt INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
