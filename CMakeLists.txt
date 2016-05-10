CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

# Support for CMake 2.6
#IF( COMMAND CMAKE_POLICY )
#  CMAKE_POLICY(SET CMP0003 NEW)
#ENDIF( COMMAND CMAKE_POLICY )

# CMake 2.8 stuff
#SET( CMAKE_LEGACY_CYGWIN_WIN32 0 ) # Remove when CMake >= 2.8.4 is required

# This is the iona private libraries project.
PROJECT(iona)

FIND_PACKAGE(VXL REQUIRED)
IF(VXL_FOUND)
  # include the standard stuff, such as Dart test
  SET(VXL_PROVIDE_STANDARD_OPTIONS 1)
  INCLUDE(${VXL_CMAKE_DIR}/UseVXL.cmake)
ELSE(VXL_FOUND)
  IF( VXL_BINARY_PATH )
    SET( VXL_DIR ${VXL_BINARY_PATH} )
    MESSAGE( "Use preferred VXL_DIR in place of VXL_BINARY_PATH" )
  ENDIF( VXL_BINARY_PATH )
ENDIF(VXL_FOUND)

SET (LIBRARY_OUTPUT_PATH ${iona_BINARY_DIR}/lib CACHE PATH "Single output directory for building all libraries.")
IF( NOT EXECUTABLE_OUTPUT_PATH )
    SET( EXECUTABLE_OUTPUT_PATH "." )
ENDIF( NOT EXECUTABLE_OUTPUT_PATH )

# BEGIN QT
# Code from: https://www.kdab.com/using-cmake-with-qt-5/
# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
#set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
# END QT

# This is to make all subdirs accessible to programs in the project
INCLUDE_DIRECTORIES( ${iona_SOURCE_DIR} )

#compile each directory
set(common_libraries
	rti
	gui
	tinyxml2
    )
foreach( _lib ${common_libraries} )
  add_subdirectory( ${_lib} )
endforeach()

add_subdirectory(executables)
