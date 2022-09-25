cmake_minimum_required(VERSION 3.15)
project(classMemberFunctoin
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus classMemberFunctoin"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} 
${Headers}
main.cpp
)

message(STATUS ${PROJECT_NAME})