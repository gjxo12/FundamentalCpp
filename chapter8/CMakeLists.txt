cmake_minimum_required(VERSION 3.15)
project(chapter8
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter8"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(basic)
add_subdirectory(inheritanceVirtual)
add_subdirectory(vfuncCall)
add_subdirectory(vconsdes)
add_subdirectory(purevirtual)
add_subdirectory(multiinheritvirtual)

message(STATUS ${PROJECT_NAME} )