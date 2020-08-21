cmake_minimum_required(VERSION 3.0.0)

project("gemm")

set(PROG1 "gemm")
set(PROG2 "gemm-mpi")

#if package cannot be found, try "export PATH=$PATH:/opt/openmpi/bin" or things like that.
find_package(MPI REQUIRED)

add_executable(${PROG1} gemm.cc)
add_executable(${PROG2} gemm-mpi.cc)

target_include_directories(${PROG1} PRIVATE ${MPI_CXX_INCLUDE_DIRS})
target_include_directories(${PROG2} PRIVATE ${MPI_CXX_INCLUDE_DIRS})

target_link_libraries(${PROG1} ${MPI_CXX_LIBRARIES})
target_link_libraries(${PROG2} ${MPI_CXX_LIBRARIES})

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -g -fopenmp")
SET(GCC_COVERAGE_LINK_FLAGS    "")

if(MPI_COMPILE_FLAGS)
  set_target_properties(${PROG1} PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
  set_target_properties(${PROG2} PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(${PROG1} PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
  set_target_properties(${PROG2} PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
