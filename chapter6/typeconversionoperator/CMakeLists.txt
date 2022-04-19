cmake_minimum_required(VERSION 3.15)
project(chapter6_TypeConversionOperator
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter6/initializeList"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

set(Headers)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter6/)

add_executable(TypeConversionOperator
  ${Headers}
  typeconversionoperator.cpp
)

target_include_directories(
  InitializeList
  PRIVATE $<BUILD_INTERFACE:${Funcdmental_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/chapter6> $<INSTALL_INTERFACE:include>
)

message("chapter6 TypeConversionOperator Complete!!!")
message(STATUS ${PROJECT_NAME} )

