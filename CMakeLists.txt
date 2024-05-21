cmake_minimum_required(VERSION 3.10)

# Project name and version
project(HelloWtApp2 VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(
        "${CMAKE_SOURCE_DIR}/include"
)

file(GLOB_RECURSE SOURCES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.c
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.css
        ${CMAKE_SOURCE_DIR}/src/*.h
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.html
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.js
        ${CMAKE_SOURCE_DIR}/docroot/resources/*.c
)

# Add an executable
add_executable(HelloWtApp2 ${SOURCES})

# Link libraries
target_link_libraries(HelloWtApp2
        "${CMAKE_SOURCE_DIR}/lib/wtd.lib"
        "${CMAKE_SOURCE_DIR}/lib/wthttpd.lib"
        "${CMAKE_SOURCE_DIR}/lib/wtdbo.lib"
        "${CMAKE_SOURCE_DIR}/lib/wtdbosqlite3.lib"
        "${CMAKE_SOURCE_DIR}/lib/wtdbopostgres.lib"
        "${CMAKE_SOURCE_DIR}/lib/wtdbomysql.lib"
)

# Specify the executable's working directory (optional)
set_target_properties(HelloWtApp2 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy DLLs to the output directory
add_custom_command(TARGET HelloWtApp2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/bin/wttestd.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtd.dll"
        "${CMAKE_SOURCE_DIR}/bin/libcrypto-1_1.dll"
        "${CMAKE_SOURCE_DIR}/bin/libssl-1_1.dll"
        "${CMAKE_SOURCE_DIR}/bin/libcrypto-1_1d.dll"
        "${CMAKE_SOURCE_DIR}/bin/libssl-1_1d.dll"
        "${CMAKE_SOURCE_DIR}/bin/libhpdf.dll"
        "${CMAKE_SOURCE_DIR}/bin/libhpdfd.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbopostgres.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbomssqlserver.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbo.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbomysql.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbosqlite3.dll"
        "${CMAKE_SOURCE_DIR}/bin/wthttp.dll"
        "${CMAKE_SOURCE_DIR}/bin/wt.dll"
        "${CMAKE_SOURCE_DIR}/bin/wttest.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbopostgresd.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbomssqlserverd.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbomysqld.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbod.dll"
        "${CMAKE_SOURCE_DIR}/bin/wtdbosqlite3d.dll"
        "${CMAKE_SOURCE_DIR}/bin/wthttpd.dll"
        $<TARGET_FILE_DIR:HelloWtApp2>
)


