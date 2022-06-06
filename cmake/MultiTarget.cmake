function(get_custom_target var)
 get_directory_property(subdirs SUBDIRECTORIES)
  foreach(subdir ${subdirs})
  if(subdir MATCHES "classtypeconversion") 
    continue()
  endif()
  get_directory_property(target DIRECTORY ${subdir} BUILDSYSTEM_TARGETS)
  list(APPEND all_targets ${target})
  endforeach()

message(STATUS "var ------------------------> ${var}")
if(var MATCHES "chapter5")
add_custom_target(
    ${PROJECT_NAME}
    COMMENT 
      "This is ${PROJECT_NAME} all target Binary" 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND
      ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${all_targets} Vector
      --config $<IF:$<CONFIG:Debug>,Debug,Release> --parallel
      ${CMAKE_BUILD_PARALLEL_LEVEL}
  )
else()
add_custom_target(
    ${PROJECT_NAME}
    COMMENT 
      "This is ${PROJECT_NAME} all target Binary" 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND
      ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${all_targets} 
      --config $<IF:$<CONFIG:Debug>,Debug,Release> --parallel
      ${CMAKE_BUILD_PARALLEL_LEVEL}
  )
endif()


message("All targets: ${all_targets}")
endfunction()

macro(get_all_targets_recursive targets dir)
endmacro()
