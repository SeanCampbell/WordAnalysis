# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_fwd.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_pixel.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_stream.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_file_format.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_byte_swap.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_16bit.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_32bit.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_rgb.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_rgb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_rgba.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_rgba.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_rgb_byte.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_property.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_stream_fstream.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_stream_core.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_stream_section.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_file_image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_memory_image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_image_proxy.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_memory_image_of.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_memory_image_of.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_memory_image_of_format.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_memory_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_crop_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_skip_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_resample_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_flipud_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_flip_components_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_block_cache_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_clamp_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_clamp_image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_scale_intensities_image_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_scale_intensities_image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_vil.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_gen.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_pnm.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_viff.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_viff_support.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_viffheader.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_iris.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_mit.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_bmp_file_header.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_bmp_core_header.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_bmp_info_header.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_bmp.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_gif.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_ras.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_image_as.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_new.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_open.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_load.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_save.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_copy.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_crop.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_skip.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_resample.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_warp.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_warp.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_flipud.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_flip_components.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_smooth.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_clamp.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_scale_intensities.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_convolve.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_convolve.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_convolve_1d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_convolve_1d_x.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_convolve_1d_y.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_convolve_simple.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_convolve_simple.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_interpolate.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_interpolate.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_ncc.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_ncc.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_resample_image.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_resample_image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_ssd.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_ssd.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_pyramid.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_colour_space.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_memory_image_window.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_ip_traits.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_png.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/vil1_jpeglib.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_jpeg.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_jpeg_source_mgr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_jpeg_decompressor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_jpeg_destination_mgr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_jpeg_compressor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vil1/file_formats" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vil1/file_formats/vil1_tiff.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvil1.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvil1.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvil1.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvil1.a")
  endif()
endif()

