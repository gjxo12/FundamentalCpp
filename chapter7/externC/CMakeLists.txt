cmake_minimum_required(VERSION 3.15)
project(chapter7_externC
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter7_externC"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} Test1.c Test2.cpp)
message(STATUS ${PROJECT_NAME})