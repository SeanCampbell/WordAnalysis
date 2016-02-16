# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_optimize_camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_camera_compute.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_camera_convert.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_camera_homographies.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_fm_compute_7_point.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_fm_compute_8_point.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_fm_compute_2_point.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_em_compute_5_point.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_em_compute_5_point.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_invmap_cost_function.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_backproject.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_ray.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_ray_intersect.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_ortho_procrustes.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_rational_adjust_onept.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_rational_adjust.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_rational_adjust_multipt.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_triangulate_points.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_bundle_adjust.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_bundle_adjust_lsqr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_ba_fixed_k_lsqr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_ba_shared_k_lsqr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vpgl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vpgl/algo/vpgl_affine_rectification.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvpgl_algo.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvpgl_algo.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvpgl_algo.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvpgl_algo.a")
  endif()
endif()

