# Install script for directory: /Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/dll.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_algo_fwd.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_netlib.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_svd.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_svd.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_svd_economy.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_svd_economy.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_svd_fixed.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_svd_fixed.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_matrix_inverse.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_matrix_inverse.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_qr.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_qr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_scatter_3x3.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_scatter_3x3.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_cholesky.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_ldl_cholesky.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_sparse_lu.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_real_eigensystem.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_complex_eigensystem.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_symmetric_eigensystem.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_symmetric_eigensystem.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_generalized_eigensystem.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_sparse_symmetric_eigensystem.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_generalized_schur.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_complex_generalized_schur.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_discrete_diff.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_levenberg_marquardt.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_sparse_lm.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_conjugate_gradient.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_lbfgs.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_lbfgsb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_amoeba.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_powell.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_brent.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_lsqr.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_solve_qp.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_bracket_minimum.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_brent_minimizer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_rpoly_roots.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_cpoly_roots.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_rnpoly_solve.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fit_parabola.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_base.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_base.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_1d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_2d.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_2d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_prime_factors.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_fft_prime_factors.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_convolve.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_convolve.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_determinant.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_determinant.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_chi_squared.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_chi_squared.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_gaussian_kernel_1d.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_adjugate.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_adjugate.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_orthogonal_complement.txx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_orthogonal_complement.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_matrix_update.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_simpson_integral.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vxl/core/vnl/algo" TYPE FILE FILES "/Users/Sean/Desktop/cs_project/vxl-tsai/core/vnl/algo/vnl_adaptsimpson_integral.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib/libvnl_algo.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvnl_algo.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvnl_algo.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvnl_algo.a")
  endif()
endif()

