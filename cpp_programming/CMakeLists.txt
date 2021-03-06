# ======================================================================
# Mandatory cmake command
# ======================================================================
cmake_minimum_required(VERSION 3.20)

# ======================================================================
# Project specific settings
# ======================================================================
project(SampleProgram
        VERSION 1.0.0.0
        DESCRIPTION "Sample program for C++ programming"
        HOMEPAGE_URL "https://github.com/sameermahant/QuickStart"
        LANGUAGES CXX)

# ======================================================================
# Common CMake settings
# ======================================================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(COMPILER_FLAGS "-march=core2 -fno-var-tracking -fexceptions -finline-functions")
set(COMPILER_WARRNINGS "-Wall -Werror -Wextra -Wno-unused-function -Wno-deprecated-declarations -Wno-sign-compare -Wunused-parameter -Wignored-qualifiers -Wtype-limits -Wduplicated-cond -Wno-class-memaccess")

set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS} ${COMPILER_WARRNINGS}")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message("Setting build type to 'RelWithDebInfo' as none was specified.")
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# ======================================================================
# External libraries / packages
# ======================================================================

# ======================================================================
# Test
# ======================================================================

# ======================================================================
# Coverage
# ======================================================================

# ======================================================================
# Package information
# ======================================================================

# ======================================================================
# Summary
# ======================================================================
message(STATUS "=== ${CMAKE_PROJECT_NAME} ===")
message(STATUS "Project version     : ${CMAKE_PROJECT_VERSION}")
message(STATUS "Project description : ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "Project homepage URL: ${CMAKE_PROJECT_HOMEPAGE_URL}")
message(STATUS "CMake build type    : ${CMAKE_BUILD_TYPE}")

# ======================================================================
# Custom Commands
# ======================================================================

# ======================================================================
# Targets / Subdirectories
# ======================================================================
add_executable(SampleProgram.exe Main.cpp)
target_link_libraries(SampleProgram.exe stdc++)
set_property(TARGET SampleProgram.exe PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
