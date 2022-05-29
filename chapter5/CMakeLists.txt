cmake_minimum_required(VERSION 3.15)
project(chapter5
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter5"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(PointerArray)
add_subdirectory(Allarray)
add_subdirectory(VLA)

add_executable(Vector
  vector.cpp
)

include(../cmake/MultiTarget.cmake)
get_custom_target(chapter5)

message(STATUS ${PROJECT_NAME} )