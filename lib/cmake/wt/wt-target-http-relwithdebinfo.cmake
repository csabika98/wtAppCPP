#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Wt::HTTP" for configuration "RelWithDebInfo"
set_property(TARGET Wt::HTTP APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Wt::HTTP PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/wthttp.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/wthttp.dll"
  )

list(APPEND _cmake_import_check_targets Wt::HTTP )
list(APPEND _cmake_import_check_files_for_Wt::HTTP "${_IMPORT_PREFIX}/lib/wthttp.lib" "${_IMPORT_PREFIX}/bin/wthttp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
