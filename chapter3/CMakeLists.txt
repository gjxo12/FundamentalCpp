cmake_minimum_required(VERSION 3.15)
project(chapter3
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

option(chapter3_err "Not use Build error code" OFF)
if(chapter3_err)
  add_subdirectory(preprocess)
endif()
add_subdirectory(macro)

message(STATUS ${PROJECT_NAME} )