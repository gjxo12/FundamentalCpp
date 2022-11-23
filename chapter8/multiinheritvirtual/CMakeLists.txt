cmake_minimum_required(VERSION 3.15)
project(chapter8.multiinheritvirtual
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter8 multiinheritvirtual"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(Headers multiinheritvirtual.h)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter8/multiinheritvirtual)



add_executable(${PROJECT_NAME} 
${Headres}
multiinheritvirtual.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/chapter8> $<INSTALL_INTERFACE:include>
)

message(STATUS ${PROJECT_NAME})