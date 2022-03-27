cmake_minimum_required(VERSION 3.15)
project(
  Funcdmental.unittest.chapter4
  VERSION 1.0
)
message(STATUS "Building: ${PROJECT_NAME}")

add_executable(
  ${PROJECT_NAME}
  Testplacementnew.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(
  ${PROJECT_NAME}
  EXTRA_ARGS --gtest_output=xml:${CMAKE_SOURCE_DIR}/gtest-report/
)