cmake_minimum_required(VERSION 3.15)
project(chapter6_constructor
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter6/constructor"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

set(Headers)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter6/constructor)

add_executable(constructor
  ${Headers}
  call.cpp
  ImplConstructor.cpp
  ImplDestructor.cpp
)

target_include_directories(
  constructor
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/chapter6> $<INSTALL_INTERFACE:include>
)

message("chapter6 constructor Complete!!!")
message(STATUS ${PROJECT_NAME} )

