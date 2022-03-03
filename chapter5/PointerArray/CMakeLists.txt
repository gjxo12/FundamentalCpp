cmake_minimum_required(VERSION 3.15)
project(chapter5_pointerarray
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter5/PointerArray"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(PointerArray
  PointerArr.cpp
)

message("chapter5 PointerArray Complete!!!")
message(STATUS ${PROJECT_NAME} )