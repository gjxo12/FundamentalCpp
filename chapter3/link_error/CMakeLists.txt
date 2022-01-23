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

list(TRANSFORM Headers PREPEND ${CMAKE_SOURCE_DIR}/chapter3/include/)
list(TRANSFORM Headers2 PREPEND ${CMAKE_SOURCE_DIR}/chapter3/include/)

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

message("chapter3 Link_error Complete!!!")
message(STATUS ${PROJECT_NAME} )