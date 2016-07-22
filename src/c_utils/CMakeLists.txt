cmake_minimum_required(VERSION 3.0)

project(c_utils)

set(C_UTILS_SRCS c_utils.c memusage.c walltime_c.c)

add_library(c_utils SHARED ${C_UTILS_SRCS})
target_include_directories(c_utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
