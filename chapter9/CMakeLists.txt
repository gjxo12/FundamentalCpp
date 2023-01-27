cmake_minimum_required(VERSION 3.15)
project(chapter9
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter9"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(FPtypedef)


message(STATUS ${PROJECT_NAME} )