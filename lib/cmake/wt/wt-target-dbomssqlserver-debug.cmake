#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Wt::DboMSSQLServer" for configuration "Debug"
set_property(TARGET Wt::DboMSSQLServer APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Wt::DboMSSQLServer PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/wtdbomssqlserverd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/wtdbomssqlserverd.dll"
  )

list(APPEND _cmake_import_check_targets Wt::DboMSSQLServer )
list(APPEND _cmake_import_check_files_for_Wt::DboMSSQLServer "${_IMPORT_PREFIX}/lib/wtdbomssqlserverd.lib" "${_IMPORT_PREFIX}/bin/wtdbomssqlserverd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
