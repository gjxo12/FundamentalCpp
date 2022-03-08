cmake_minimum_required(VERSION 3.15)
project(chapter6_member
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3/macro"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

# header file in chapter3
set(Headers)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter6/)

add_executable(member
  ${Headers}
  class_struct.cpp
  empty.cpp
)

target_include_directories(
  member
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/chapter3> $<INSTALL_INTERFACE:include>
)

message("chapter6 member Complete!!!")
message(STATUS ${PROJECT_NAME} )

