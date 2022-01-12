cmake_minimum_required(VERSION 3.15)
project(chapter3_preprocess
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3/preprocess/src"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

# header file in chapter3
set(Headers Common.h)
list(TRANSFORM Headers PREPEND ${CMAKE_SOURCE_DIR}/chapter3/include/)
# include_directories(Headers chapter3/include/)

add_executable(preprocess01
  ${Headers}
  A.cpp
  B.cpp
)
message("chapter3 preprocess Complete!!!")
message(STATUS ${PROJECT_NAME} )