# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_sobel_1x3.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_sobel_1x3.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_sobel_3x3.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_sobel_3x3.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_gauss_filter.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_gauss_filter.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_gauss_reduce.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_gauss_reduce.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_median.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_median.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_structuring_element.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_binary_dilate.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_binary_erode.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_greyscale_dilate.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_greyscale_dilate.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_greyscale_erode.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_greyscale_erode.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_greyscale_opening.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_greyscale_closing.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_binary_opening.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_binary_closing.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_convolve_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_convolve_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_correlate_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_correlate_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_dog_filter_5tap.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_dog_pyramid.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_exp_filter_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_normalised_correlation_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_exp_grad_filter_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_exp_filter_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_suppress_non_max.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_suppress_non_plateau.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_quad_distance_function.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_suppress_non_max_edges.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_suppress_non_max_edges.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_line_filter.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_line_filter.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_threshold.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_threshold.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_grid_merge.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_find_4con_boundary.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_find_peaks.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_find_plateaus.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_fft.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_fft.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_histogram.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_histogram_equalise.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_blob.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_distance_transform.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_corners.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_region_finder.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_region_finder.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_cartesian_differential_invariants.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_cartesian_differential_invariants.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_tile_images.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_orientations.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_colour_space.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_abs_shuffle_distance.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_abs_shuffle_distance.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_checker_board.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_checker_board.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil/algo/vil_flood_fill.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvil_algo.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvil_algo.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvil_algo.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvil_algo.a")
  endif()
endif()

