cmake_minimum_required(VERSION 3.15)
project(chapter3
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter3"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

#option(ALL_Option_On "Not use Build error code" OFF)
if(ALL_Option_On)
  add_subdirectory(link_error)
  add_subdirectory(preprocess)
endif()
add_subdirectory(macro)

include(../cmake/MultiTarget.cmake)
get_custom_target(chapter3)


message(STATUS "ALL_Option_On: " ${ALL_Option_On} )
message(STATUS ${PROJECT_NAME} )