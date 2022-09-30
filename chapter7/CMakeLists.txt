cmake_minimum_required(VERSION 3.15)
project(chapter7
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter7"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(externC)
add_subdirectory(callby)
add_subdirectory(returnType)
add_subdirectory(variableArg)
add_subdirectory(classMemberFunctoin)
add_subdirectory(Functor)

message(STATUS ${PROJECT_NAME} )