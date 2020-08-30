cmake_minimum_required(VERSION 3.0.0)

project("hdf5")

set(PROG1 "pwrite")
set(PROG2 "pread")

find_package(HDF5 REQUIRED)
find_package(MPI REQUIRED)

add_executable(${PROG1} pwrite.c)
add_executable(${PROG2} pread.c)

target_include_directories(${PROG1} PRIVATE ${MPI_C_INCLUDE_DIRS} ${HDF5_C_INCLUDE_DIRS})
target_include_directories(${PROG2} PRIVATE ${MPI_C_INCLUDE_DIRS} ${HDF5_C_INCLUDE_DIRS})

message("mpi  inc = " ${MPI_C_INCLUDE_DIRS})
message("hdf5 inc = " ${HDF5_C_INCLUDE_DIRS})
message("mpi libs = " ${MPI_C_LIBRARIES})
message("hdf5 libs = " ${HDF5_C_LIBRARIES})
target_link_libraries(${PROG1} ${MPI_C_LIBRARIES} ${HDF5_C_LIBRARIES})
target_link_libraries(${PROG2} ${MPI_C_LIBRARIES} ${HDF5_C_LIBRARIES})

if(MPI_COMPILE_FLAGS)
  set_target_properties(${PROG1} PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
  set_target_properties(${PROG2} PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(${PROG1} PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
  set_target_properties(${PROG2} PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
