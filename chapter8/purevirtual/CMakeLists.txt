cmake_minimum_required(VERSION 3.15)
project(chapter8.pureVirtual
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter8 pureVirtual"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(Headers purevirtual.h foo.h)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter8/purevirtual/)

message("Header file: ${Headers}")

add_executable(${PROJECT_NAME} 
${Headres}
foo.cpp
purevirtual.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/chapter8> $<INSTALL_INTERFACE:include>
)

message(STATUS ${PROJECT_NAME})