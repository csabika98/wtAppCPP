#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Wt::Wt" for configuration "Debug"
set_property(TARGET Wt::Wt APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Wt::Wt PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/wtd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/wtd.dll"
  )

list(APPEND _cmake_import_check_targets Wt::Wt )
list(APPEND _cmake_import_check_files_for_Wt::Wt "${_IMPORT_PREFIX}/lib/wtd.lib" "${_IMPORT_PREFIX}/bin/wtd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
