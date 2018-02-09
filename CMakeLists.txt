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


add_executable(LaSi src/main.cpp inc/mathematics.h src/mathematics.cpp inc/physics.h src/physics.cpp inc/generate.h inc/global.h src/generate.cpp inc/photon.h inc/muon.h src/muon.cpp src/WLS.cpp inc/WLS.h inc/data.h src/analysis.cpp inc/analysis.h)
target_link_libraries(LaSi ${ROOT_LIBRARIES})