# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/v3p

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/netlib/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/zlib/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/bzlib/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/jpeg/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/j2k/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/tiff/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/geotiff/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/png/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/dcmtk/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/openjpeg2/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/v3p/rply/cmake_install.cmake")

endif()

