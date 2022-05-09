cmake_minimum_required(VERSION 3.15)
project(chapter2
  VERSION 1.0
  DESCRIPTION "Funcdmental Cplusplus chapter2"
)
message(STATUS "Building: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(class_def)
add_subdirectory(extern_static)
add_subdirectory(static_val)

function(get_all_targets var)
    set(targets)
    get_all_targets_recursive(targets ${CMAKE_CURRENT_SOURCE_DIR})
    set(${var} ${targets} PARENT_SCOPE)
endfunction()

macro(get_all_targets_recursive targets dir)
    get_property(subdirectories DIRECTORY ${dir} PROPERTY SUBDIRECTORIES)
    foreach(subdir ${subdirectories})
        get_all_targets_recursive(${targets} ${subdir})
    endforeach()

    get_property(current_targets DIRECTORY ${dir} PROPERTY BUILDSYSTEM_TARGETS)
    list(APPEND ${targets} ${current_targets})
endmacro()

#if(ENT_TESTS)
  
  # Exclude unit tests from building ALL.
  get_all_targets(all_targets)
  #if(ENABLE_DEV)
    #set(folder_name "${PROJECT_NAME}/chapter2")
    #list(REMOVE_ITEM all_targets "gtest" "gtest_main" "gmock" "gmock_main")
    #foreach(test_target ${all_targets})
    #  get_target_property(test_target_type ${test_target} TYPE)
    #endforeach()

    set(folder_name "All_chapter2")
  foreach(test_target ${all_targets})
    set_target_properties(${all_targets} PROPERTIES FOLDER ${folder_name})
    set_target_properties(${all_targets} PROPERTIES EXCLUDE_FROM_ALL TRUE)
  endforeach()
#endif()


#get_all_targets(all_targets)
message("All targets: ${all_targets}")

message(STATUS ${PROJECT_NAME} )