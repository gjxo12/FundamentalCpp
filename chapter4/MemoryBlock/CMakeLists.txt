cmake_minimum_required(VERSION 3.15)
project(chapter4_Memoryblock
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter4/MemoryBlock"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(Memoryblock
  Memoryblock.cpp
)

message("chapter4 MemoryBlock Complete!!!")
message(STATUS ${PROJECT_NAME} )