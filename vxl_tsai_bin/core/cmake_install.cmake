# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vxl_copyright.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vxl_version.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vxl_config.h")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/testlib/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vpl/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vul/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vbl/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vnl/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vgl/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vil/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vil/algo/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vil1/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vsl/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vul/io/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vbl/io/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vnl/io/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vnl/xio/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vgl/io/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vgl/xio/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vil/io/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vil1/io/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vcsl/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vpgl/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vgui/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vidl/cmake_install.cmake")

endif()

