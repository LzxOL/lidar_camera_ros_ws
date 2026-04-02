# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_vimbax_camera_examples_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED vimbax_camera_examples_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(vimbax_camera_examples_FOUND FALSE)
  elseif(NOT vimbax_camera_examples_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(vimbax_camera_examples_FOUND FALSE)
  endif()
  return()
endif()
set(_vimbax_camera_examples_CONFIG_INCLUDED TRUE)

# output package information
if(NOT vimbax_camera_examples_FIND_QUIETLY)
  message(STATUS "Found vimbax_camera_examples: 1.0.2 (${vimbax_camera_examples_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'vimbax_camera_examples' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${vimbax_camera_examples_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(vimbax_camera_examples_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${vimbax_camera_examples_DIR}/${_extra}")
endforeach()
