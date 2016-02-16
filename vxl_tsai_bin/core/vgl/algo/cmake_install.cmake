# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_algo_fwd.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_rtree.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_rtree.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_orient_box_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_orient_box_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_ellipsoid_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_ellipsoid_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_homg_operators_1d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_homg_operators_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_homg_operators_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_homg_operators_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_homg_operators_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_homg_operators_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_1d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_p_matrix.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_p_matrix.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_norm_trans_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_norm_trans_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_norm_trans_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_norm_trans_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_compute_similarity_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_compute_similarity_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_1d_compute.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_1d_compute_linear.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_1d_compute_3point.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_1d_compute_optimize.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d_compute.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d_compute_linear.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d_compute_4point.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d_compute_rigid_body.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_line_2d_regression.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_line_2d_regression.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_fit_lines_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_fit_lines_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_convex_hull_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_convex_hull_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d_optimize.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_2d_optimize_lmq.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_conic_2d_regression.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_conic_2d_regression.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_fit_conics_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_fit_conics_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_fit_plane_3d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_fit_plane_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_intersection.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_intersection.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_rotation_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_rtree_c.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_orient_box_3d_operators.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_orient_box_3d_operators.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_3d_compute.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vgl/algo/vgl_h_matrix_3d_compute_linear.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvgl_algo.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvgl_algo.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvgl_algo.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvgl_algo.a")
  endif()
endif()

