#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "vimbax_camera_events::vimbax_camera_events" for configuration ""
set_property(TARGET vimbax_camera_events::vimbax_camera_events APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(vimbax_camera_events::vimbax_camera_events PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libvimbax_camera_events.so"
  IMPORTED_SONAME_NOCONFIG "libvimbax_camera_events.so"
  )

list(APPEND _cmake_import_check_targets vimbax_camera_events::vimbax_camera_events )
list(APPEND _cmake_import_check_files_for_vimbax_camera_events::vimbax_camera_events "${_IMPORT_PREFIX}/lib/libvimbax_camera_events.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
