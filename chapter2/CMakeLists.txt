cmake_minimum_required(VERSION 3.15)
project(chapter2
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter2"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(class_def)
add_subdirectory(extern_static)
add_subdirectory(static_val)

message(STATUS ${PROJECT_NAME} )