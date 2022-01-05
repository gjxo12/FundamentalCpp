cmake_minimum_required(VERSION 3.15)
project(Funcdmental_Test
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus unittest"
)
message(STATUS "Building: ${PROJECT_NAME}")

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