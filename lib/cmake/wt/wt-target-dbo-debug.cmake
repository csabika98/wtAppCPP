#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Wt::Dbo" for configuration "Debug"
set_property(TARGET Wt::Dbo APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Wt::Dbo PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/wtdbod.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/wtdbod.dll"
  )

list(APPEND _cmake_import_check_targets Wt::Dbo )
list(APPEND _cmake_import_check_files_for_Wt::Dbo "${_IMPORT_PREFIX}/lib/wtdbod.lib" "${_IMPORT_PREFIX}/bin/wtdbod.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
