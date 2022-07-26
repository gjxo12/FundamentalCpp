cmake_minimum_required(VERSION 3.15)
project(chapter7_externC
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter7_externC"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

set(Headers)
list(TRANSFORM Headers PREPEND ${Funcdmental_SOURCE_DIR}/include/chapter7/)

add_executable(${PROJECT_NAME} 
${Headers}
Test1.c Test2.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${Funcdmental_SOURCE_DIR}/include/)

message(STATUS ${PROJECT_NAME})