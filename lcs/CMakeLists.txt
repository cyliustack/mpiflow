cmake_minimum_required(VERSION 3.0.0)

project('bioinfo.lcs')

find_package(MPI REQUIRED)

set(PROG1 "lcs-omp")
set(PROG2 "lcs-mpi")

add_executable(${PROG1} lcs-omp.cc)
add_executable(${PROG2} lcs-mpi.cc)

target_include_directories(${PROG1} PRIVATE ${MPI_CXX_INCLUDE_DIRS})
target_include_directories(${PROG2} PRIVATE ${MPI_CXX_INCLUDE_DIRS})

target_link_libraries(${PROG1} ${MPI_CXX_LIBRARIES})
target_link_libraries(${PROG2} ${MPI_CXX_LIBRARIES})

if(MPI_COMPILE_FLAGS)
  set_target_properties(${PROG1} PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
  set_target_properties(${PROG2} PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(${PROG1} PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
  set_target_properties(${PROG2} PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
