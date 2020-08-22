cmake_minimum_required(VERSION 3.0.0)

set(PROG "memrw")

add_executable(${PROG} memrw.cc)

target_include_directories(${PROG} PUBLIC ~/eigen/include)
SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -g -fopenmp")
SET(GCC_COVERAGE_LINK_FLAGS    "")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

