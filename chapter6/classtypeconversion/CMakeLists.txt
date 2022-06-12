cmake_minimum_required(VERSION 3.15)
project(chapter6_classtypeconversion
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter6/classtypeconversion"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

set(Headers)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter6/)

add_executable(classtypeconversion
  ${Headers}
  main.cpp
)

target_include_directories(
  classtypeconversion
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/chapter6> $<INSTALL_INTERFACE:include>
)

message("chapter6 classtypeconversion Complete!!!")
message(STATUS ${PROJECT_NAME} )

