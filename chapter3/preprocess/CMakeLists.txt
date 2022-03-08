cmake_minimum_required(VERSION 3.15)
project(chapter3_preprocess
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3/preprocess/src"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

# header file in chapter3
set(Headers Common.h)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter3/)
# include_directories(Headers chapter3/include/)

add_library(preprocess
  ${Headers}
  A.cpp
  B.cpp
)

target_include_directories(
  preprocess
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/chapter3>
          $<INSTALL_INTERFACE:include/chapter3> $<INSTALL_INTERFACE:include>)

message("chapter3 preprocess Complete!!!")
message(STATUS ${PROJECT_NAME} )