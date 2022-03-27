cmake_minimum_required(VERSION 3.15)
project(
  Funcdmental.unittest.chapter5
  VERSION 1.0
)
message(STATUS "Building: ${PROJECT_NAME}")


set(libHeaders chapter5.h)
list(TRANSFORM libHeaders PREPEND ${PROJECT_SOURCE_DIR}/include/)

add_executable(${PROJECT_NAME} ${libHeaders} chapter5.cpp)
include(GoogleTest)
gtest_discover_tests(
  ${PROJECT_NAME}
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  $<BUILD_INTERFACE:${gtest_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(
  ${PROJECT_NAME}
  gtest_main
)

gtest_discover_tests(
  ${PROJECT_NAME}
  EXTRA_ARGS --gtest_output=xml:${CMAKE_SOURCE_DIR}/gtest-report/
)
