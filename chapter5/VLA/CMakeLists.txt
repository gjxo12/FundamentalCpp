cmake_minimum_required(VERSION 3.15)
project(chapter5_VLA
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter5/VLA"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)


add_executable(VLA
  vla.cpp
)

message("chapter5 VLA Complete!!!")
message(STATUS ${PROJECT_NAME} )