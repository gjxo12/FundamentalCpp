cmake_minimum_required(VERSION 3.15)
project(chapter4
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter4"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

#option(ALL_Option_On "Not use Build error code" OFF)
#add_subdirectory(macro)

add_subdirectory(basic)
add_subdirectory(placement_new)
add_subdirectory(MemoryBlock)
message(STATUS ${PROJECT_NAME} )