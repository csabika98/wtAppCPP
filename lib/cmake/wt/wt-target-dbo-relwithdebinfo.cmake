#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Wt::Dbo" for configuration "RelWithDebInfo"
set_property(TARGET Wt::Dbo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Wt::Dbo PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/wtdbo.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/wtdbo.dll"
  )

list(APPEND _cmake_import_check_targets Wt::Dbo )
list(APPEND _cmake_import_check_files_for_Wt::Dbo "${_IMPORT_PREFIX}/lib/wtdbo.lib" "${_IMPORT_PREFIX}/bin/wtdbo.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
