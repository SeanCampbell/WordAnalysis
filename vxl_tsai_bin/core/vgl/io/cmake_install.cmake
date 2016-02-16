# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_polygon.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_box_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_box_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_box_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_box_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_conic.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_conic.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_line_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_line_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_line_3d_2_points.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_line_3d_2_points.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_plane_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_plane_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_point_1d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_point_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_point_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_point_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_point_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_homg_point_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_3d_2_points.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_3d_2_points.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_segment_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_segment_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_segment_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_line_segment_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_plane_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_plane_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_point_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_point_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_point_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_point_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_vector_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_vector_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_vector_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_vector_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_cylinder.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_cylinder.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_infinite_line_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_infinite_line_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_h_matrix_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/io" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/io/vgl_io_h_matrix_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvgl_io.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvgl_io.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvgl_io.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvgl_io.a")
  endif()
endif()

