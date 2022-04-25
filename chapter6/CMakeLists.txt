cmake_minimum_required(VERSION 3.15)
project(chapter6
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter6"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(member)
add_subdirectory(cons)
add_subdirectory(copyoperation)
add_subdirectory(initialzieList)
add_subdirectory(typeconversionoperator)
add_subdirectory(inheritane)

message(STATUS ${PROJECT_NAME} )