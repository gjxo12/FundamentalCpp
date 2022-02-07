cmake_minimum_required(VERSION 3.15)
project(chapter4_basic
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter4/basic"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(delete_example
  delete_example.cpp
)

message("chapter4 basic Complete!!!")
message(STATUS ${PROJECT_NAME} )