cmake_minimum_required(VERSION 3.15)
project(chapter3_macro
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3/macro"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

# header file in chapter3
set(Headers macro_A.h macro_B.h)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter3/)

add_executable(macro2
  ${Headers}
  main.cpp
)

target_include_directories(
  macro2
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
          $<INSTALL_INTERFACE:include/chapter3> $<INSTALL_INTERFACE:include>)

message("chapter3 macro Complete!!!")
message(STATUS ${PROJECT_NAME} )
message(STATUS ${Headers})