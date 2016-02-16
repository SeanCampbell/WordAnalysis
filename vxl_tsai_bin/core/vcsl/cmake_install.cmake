# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_dimension.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_dimension_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_length.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_length_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_angle.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_angle_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_unit.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_unit_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_length_unit.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_length_unit_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_meter.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_meter_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_millimeter.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_millimeter_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_micron.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_micron_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_angle_unit.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_angle_unit_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_radian.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_radian_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_degree.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_degree_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_axis.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_axis_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_coordinate_system.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_coordinate_system_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cartesian.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cartesian_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spatial.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spatial_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_graph.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_graph_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cartesian_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cartesian_2d_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cartesian_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cartesian_3d_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_polar.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_polar_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cylindrical.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cylindrical_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spherical.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spherical_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spheroid.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spheroid_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_geographic.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_geographic_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_utm.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_utm_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_geocentric.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_geocentric_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_geodetic.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_geodetic_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_lambertian.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_lambertian_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spatial_transformation.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_spatial_transformation_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_composition.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_composition_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_scale.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_scale_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_translation.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_translation_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_rotation.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_rotation_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_displacement.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_displacement_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cylindrical_to_cartesian_3d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_cylindrical_to_cartesian_3d_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_perspective.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_perspective_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_matrix.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_matrix_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_matrix_param.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vcsl" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vcsl/vcsl_matrix_param_sptr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvcsl.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvcsl.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvcsl.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvcsl.a")
  endif()
endif()

