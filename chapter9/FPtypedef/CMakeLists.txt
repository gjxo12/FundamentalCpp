cmake_minimum_required(VERSION 3.15)
project(chapter9.FPtypedef
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter9 thisWithFunction Pointer.."
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} 
thisWithFp.cpp
)

message(STATUS ${PROJECT_NAME})