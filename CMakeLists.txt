cmake_minimum_required(VERSION 3.15)
project(Funcdmental
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus"
)
message(STATUS "Building: ${PROJECT_NAME}")
#set(CMAKE_CXX_STANDARD 20)

include(cmake/Warning.cmake)

if(MSVC)
add_compile_options(/std:c++20 ${MSVC_options})
endif()

add_subdirectory(chapter1)
add_subdirectory(chapter2)
add_subdirectory(chapter3)
add_subdirectory(chapter4)
add_subdirectory(chapter5)
add_subdirectory(chapter6)
add_subdirectory(chapter7)
add_subdirectory(chapter8)

#include(cmake/SuperBuild.cmake)
#get_all_targets(all_target ${Funcdmental_SOURCE_DIR})

#foreach(all_target ${all_target})
    #add_dependencies(${all_target} library1)
    #add_dependencies(${all_target} library2)
#    set_target_properties(${all_target} PROPERTIES FOLDER Funcdmental)
#  endforeach()

enable_testing()
add_subdirectory(tests)

set(forlder_name "unittest")

foreach(test_target ${test_targets})
    set_target_properties(${test_target} PROPERTIES FOLDER ${folder_name})
    set_target_properties(${test_target} PROPERTIES EXCLUDE_FROM_ALL TRUE)
endforeach()
