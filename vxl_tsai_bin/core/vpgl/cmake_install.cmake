# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_camera_double_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_camera_float_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_proj_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_proj_camera.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_calibration_matrix.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_calibration_matrix.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_perspective_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_perspective_camera.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_affine_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_affine_camera.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_fundamental_matrix.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_fundamental_matrix.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_essential_matrix.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_essential_matrix.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_affine_fundamental_matrix.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_affine_fundamental_matrix.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_rational_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_rational_camera.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_local_rational_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_local_rational_camera.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_generic_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_generic_camera.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_dll.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_lvcs.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_lvcs_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_utm.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_earth_constants.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/vpgl_datum_conversion.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvpgl.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvpgl.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvpgl.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvpgl.a")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vpgl/algo/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vpgl/file_formats/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vpgl/io/cmake_install.cmake")
  include("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core/vpgl/xio/cmake_install.cmake")

endif()

