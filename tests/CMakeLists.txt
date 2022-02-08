cmake_minimum_required(VERSION 3.15)
project(Funcdmental.unittest
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus unittest"
)
message(STATUS "Building: ${PROJECT_NAME}")

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(chapter4)

add_executable(
  ${PROJECT_NAME}
  test.cpp
)
target_link_libraries(
  ${PROJECT_NAME}
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(
    ${PROJECT_NAME}
    #EXTRA_ARGS --gtest_output=xml:${enterprise_SOURCE_DIR}/gtest-report/
)

