cmake_minimum_required(VERSION 3.15)
project(chapter8.this
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter8 this"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(Headers this.h thunk.h)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter8/this)



add_executable(${PROJECT_NAME} 
${Headres}
this.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/chapter8> $<INSTALL_INTERFACE:include>
)

message(STATUS ${PROJECT_NAME})