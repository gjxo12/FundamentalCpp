cmake_minimum_required(VERSION 3.15)
project(Funcdmental
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus"
)
message(STATUS "Building: ${PROJECT_NAME}")
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(chapter1)
add_subdirectory(chapter2)
add_subdirectory(chapter3)
add_subdirectory(chapter4)
add_subdirectory(chapter5)
add_subdirectory(chapter6)

enable_testing()
add_subdirectory(tests)

set(forlder_name "unittest")

foreach(test_target ${test_targets})
    set_target_properties(${test_target} PROPERTIES FOLDER ${folder_name})
    set_target_properties(${test_target} PROPERTIES EXCLUDE_FROM_ALL TRUE)
endforeach()
