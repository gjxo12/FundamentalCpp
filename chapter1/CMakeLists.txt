cmake_minimum_required(VERSION 3.15)
project(chapter1
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter1"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} chapter1.cpp)
message(STATUS ${PROJECT_NAME})