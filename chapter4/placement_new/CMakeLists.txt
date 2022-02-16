cmake_minimum_required(VERSION 3.15)
project(chapter4_placementnew
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter4/placement_new"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(placement_new
  placement_new.cpp
)

message("chapter4 placement_new Complete!!!")
message(STATUS ${PROJECT_NAME} )