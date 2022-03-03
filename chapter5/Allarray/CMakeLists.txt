cmake_minimum_required(VERSION 3.15)
project(chapter5_Allarray
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter5/array"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -m32)


add_executable(AllArray
  array.cpp
)

message("chapter5 AllArray Complete!!!")
message(STATUS ${PROJECT_NAME} )