cmake_minimum_required(VERSION 3.9)
project(LaSi)

set(CMAKE_CXX_STANDARD 11)

#-------------------------------------------------------------------------------------------
# Find ROOT (required package) in CONFIG mode. Looking for ROOTConfig.cmake.
# Crucial for loading the proper definitions!
#

find_package(ROOT CONFIG REQUIRED)
if(NOT ROOT_FOUND)
    message(STATUS "ROOT package not found.")
    return()
endif()

## Load macros: need to compile ROOT through cmake first and execute bin/thisroot.sh
include(${ROOT_USE_FILE})
#--------------------------------------------------------------------------------------------

include_directories(${ROOT_INCLUDE_DIR})


add_executable(LaSi main.cpp mathematics.h mathematics.cpp physics.h physics.cpp generate.h global.h generate.cpp photon.h muon.h muon.cpp WLS.cpp WLS.h data.h analysis.cpp analysis.h)
target_link_libraries(LaSi ${ROOT_LIBRARIES})