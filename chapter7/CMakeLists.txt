cmake_minimum_required(VERSION 3.15)
project(chapter7
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter7"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(externC)

message(STATUS ${PROJECT_NAME} )