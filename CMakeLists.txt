cmake_minimum_required(VERSION 3.28)
project(dbo_test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH /Users/sallaicsaba/Downloads/wt/build)

file(GLOB_RECURSE SOURCES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.c
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.css
        ${CMAKE_SOURCE_DIR}/src/*.h
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.html
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.js
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.c
        ${CMAKE_SOURCE_DIR}/docroot/*.html
        ${CMAKE_SOURCE_DIR}/docroot/*.js
        ${CMAKE_SOURCE_DIR}/docroot/*.css
        ${CMAKE_SOURCE_DIR}/src/controller/*.cpp
        ${CMAKE_SOURCE_DIR}/src/controller/*.c
        ${CMAKE_SOURCE_DIR}/src/controller/*.h
        ${CMAKE_SOURCE_DIR}/src/model/*.cpp
        ${CMAKE_SOURCE_DIR}/src/model/*.c
        ${CMAKE_SOURCE_DIR}/src/model/*.h
        ${CMAKE_SOURCE_DIR}/src/view/*.cpp
        ${CMAKE_SOURCE_DIR}/src/view/*.c
        ${CMAKE_SOURCE_DIR}/src/view/*.h
)

include_directories(/usr/local/include)

## Find the libraries
#find_library(WT_LIB wt PATHS /Users/sallaicsaba/Downloads/wt/build/src)
#find_library(WTHTTP_LIB wthttp PATHS /Users/sallaicsaba/Downloads/wt/build/src/http)
#find_library(WTDBOSQLITE3_LIB wtdbosqlite3 PATHS /Users/sallaicsaba/Downloads/wt/build/src/Dbo/backend)
#find_library(WTDBO_LIB wtdbo PATHS /Users/sallaicsaba/Downloads/wt/build/src/Dbo)
## Check if the libraries were found
#if(NOT WT_LIB)
#    message(FATAL_ERROR "libwt not found")
#endif()
#if(NOT WTHTTP_LIB)
#    message(FATAL_ERROR "libwthttp not found")
#endif()

add_executable(dbo_test ${SOURCES}
        src/CUSTOM_SQL_VALUE_TRAITS.cpp)

# Set the RPATH
set_target_properties(dbo_test PROPERTIES
        INSTALL_RPATH_USE_LINK_PATH TRUE
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "/usr/local/lib;/usr/local/lib"
)

# Link the libraries
target_link_libraries(dbo_test wt wthttp wtdbo wtdbosqlite3)




