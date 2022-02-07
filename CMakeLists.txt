cmake_minimum_required(VERSION 3.15)
project(Funcdmental_C++
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus"
)
message(STATUS "Building: ${PROJECT_NAME}")
set(CMAKE_CXX_STANDARD 17)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(chapter1)
add_subdirectory(chapter2)
add_subdirectory(chapter3)
add_subdirectory(chapter4)

enable_testing()
add_subdirectory(tests)

set(forlder_name "unittest")

foreach(test_target ${test_targets})
    set_target_properties(${test_target} PROPERTIES FOLDER ${folder_name})
    set_target_properties(${test_target} PROPERTIES EXCLUDE_FROM_ALL TRUE)
endforeach()
