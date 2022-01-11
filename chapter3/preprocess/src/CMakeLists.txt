cmake_minimum_required(VERSION 3.15)
project(chapter3_preprocess_src
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3/preprocess/src"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

include_directories(project)
add_executable(preprocess01
  A.cpp
  B.cpp
)

message(STATUS ${PROJECT_NAME} )