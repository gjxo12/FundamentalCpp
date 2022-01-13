cmake_minimum_required(VERSION 3.15)
project(chapter3_macro
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3/macro"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

# header file in chapter3
set(Headers macro_A.h macro_B.h)
list(TRANSFORM Headers PREPEND ${CMAKE_SOURCE_DIR}/chapter3/include/)
# include_directories(Headers chapter3/include/)

add_executable(macro
  ${Headers}
  main.cpp
)
message("chapter3 macro Complete!!!")
message(STATUS ${PROJECT_NAME} )