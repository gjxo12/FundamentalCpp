cmake_minimum_required(VERSION 3.15)
project(extern_static
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter2/extern_static"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} A.cpp Main.cpp)

message(STATUS ${PROJECT_NAME})
#project_name은 최근에 사용된 project이름 -> 저 위에 2번 라인에 사용된 project(...)
