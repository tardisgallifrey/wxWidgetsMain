#############################################################################
# Name:        /home/tardis1/wxWidget_projects/CMakeLists.txt
# Purpose:     First app according to YouTuber OttoBotCode.
# Author:      Dave does not do pretty
# Created:     2023-12-23
# Copyright:   (c) 2016 wxWidgets development team
# Licence:     MIT
#############################################################################

# Declare the minimum required CMake version
cmake_minimum_required(VERSION 2.8.12)

if(APPLE AND NOT CMAKE_OSX_DEPLOYMENT_TARGET)
    # If no deployment target has been set default to the minimum supported
    # OS version (this has to be set before the first project() call)
    if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
        set(CMAKE_OSX_DEPLOYMENT_TARGET 12.0 CACHE STRING "iOS Deployment Target")
    else()
        set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10 CACHE STRING "macOS Deployment Target")
    endif()
endif()

# Name the project
project(firstapp)

# Request the required wxWidgets libs
find_package(wxWidgets 3.2 REQUIRED)

# Include the wxWidgets use file to initialize various settings
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

# Define a variable containing a list of source files for the project
set(SRC_FILES
        MainFrame.cpp
        MainFrame.h
        App.cpp
        App.h)

if(WIN32)
    # Include a RC file for windows
    list(APPEND SRC_FILES ../sample.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES ../../src/osx/carbon/wxmac.icns)
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RESOURCE "../../src/osx/carbon/wxmac.icns"
        MACOSX_BUNDLE_ICON_FILE wxmac.icns
        MACOSX_BUNDLE_COPYRIGHT "Copyright wxWidgets"
        MACOSX_BUNDLE_GUI_IDENTIFIER "org.wxwidgets.minimal"
        )
endif()
