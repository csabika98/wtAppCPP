#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Wt::DboSqlite3" for configuration "RelWithDebInfo"
set_property(TARGET Wt::DboSqlite3 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Wt::DboSqlite3 PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/wtdbosqlite3.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/wtdbosqlite3.dll"
  )

list(APPEND _cmake_import_check_targets Wt::DboSqlite3 )
list(APPEND _cmake_import_check_files_for_Wt::DboSqlite3 "${_IMPORT_PREFIX}/lib/wtdbosqlite3.lib" "${_IMPORT_PREFIX}/bin/wtdbosqlite3.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
