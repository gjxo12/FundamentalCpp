cmake_minimum_required(VERSION 3.15)
project(chapter3_Link_error
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3/link_error"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

# header file in chapter3
set(Headers link_A.h)
# include_directories(Headers chapter3/include/)
set(Headers2 link_A2.h)

list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter3/)
list(TRANSFORM Headers2 PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter3/)

add_executable(link_error2
  ${Headers2}
  A.cpp
  B.cpp
  main2.cpp
)

add_executable(link_error
  ${Headers}
  main.cpp
)

target_include_directories(
  link_error2
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/chapter3>
          $<INSTALL_INTERFACE:include/chapter3> $<INSTALL_INTERFACE:include>)

target_include_directories(
  link_error
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/chapter3>
          $<INSTALL_INTERFACE:include/chapter3> $<INSTALL_INTERFACE:include>)

message("chapter3 Link_error Complete!!!")
message(STATUS ${PROJECT_NAME} )