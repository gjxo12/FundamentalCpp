cmake_minimum_required(VERSION 3.15)
project(chapter3
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(preprocess)

message(STATUS ${PROJECT_NAME} )