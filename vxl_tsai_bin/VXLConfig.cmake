# vxl/config/cmake/VXLConfig.cmake.in
#   also configured by CMake to
# /Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/VXLConfig.cmake
#
# This CMake module is configured by VXL's build process to export the
# project settings for use by client projects.  A client project may
# find VXL and include this module using the FIND_PACKAGE command:
#
#  FIND_PACKAGE(VXL)
#
# After this command executes, projects may test VXL_FOUND for whether
# VXL has been found.  If so, the settings listed below in this file
# have been loaded and are available for use.
#
# Typically, a client project will include UseVXL.cmake from the
# directory specified by the VXL_CMAKE_DIR setting:
#
#  FIND_PACKAGE(VXL)
#  IF(VXL_FOUND)
#    INCLUDE(${VXL_CMAKE_DIR}/UseVXL.cmake)
#  ELSE(VXL_FOUND)
#    MESSAGE("VXL_DIR should be set to the VXL build directory.")
#  ENDIF(VXL_FOUND)
#
# See vxl/config/cmake/UseVXL.cmake for details.
#

# The build settings file.
SET(VXL_BUILD_SETTINGS_FILE "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/VXLBuildSettings.cmake")

# The VXL library dependencies.
IF(NOT VXL_NO_LIBRARY_DEPENDS)
  INCLUDE("/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/VXLLibraryDepends.cmake")
ENDIF(NOT VXL_NO_LIBRARY_DEPENDS)

# The VXL library directory.
SET(VXL_LIBRARY_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/lib")

# The VXL CMake support directory.
# Clients projects should not use the Find*.cmake files in this directory.
SET(VXL_CMAKE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/config/cmake/Modules")

# Doxygen Support
SET(VXL_CMAKE_DOXYGEN_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/config/cmake/doxygen")



# VXL Configuration options. You don't have to build with the same options as VXL, but it often helps.
SET(VXL_BUILD_SHARED_LIBS "OFF")
SET(VXL_BUILD_TESTS "")
SET(VXL_BUILD_EXAMPLES "OFF")
SET(VXL_EXTRA_CMAKE_CXX_FLAGS "")
SET(VXL_EXTRA_CMAKE_C_FLAGS "")
SET(VXL_EXTRA_CMAKE_EXE_LINKER_FLAGS "")
SET(VXL_EXTRA_CMAKE_MODULE_LINKER_FLAGS "")
SET(VXL_EXTRA_CMAKE_SHARED_LINKER_FLAGS "")

# VXL has many parts that are optional, depending on selections made
# when building.  The stanzas below give a consistent (though
# pedantic) interface to each part.  Clients use these settings to
# determine whether a part was built (_FOUND), where its headers are
# located (_INCLUDE_DIR) and in some cases what libraries must be
# linked to use the part (_LIBRARIES).  Most client projects will
# likely still refer to individual VXL libraries such as vcl, for
# example, by hard-wired "vcl" instead of using the variable
# VXL_VCL_LIBRARIES, but it is there just in case.

SET(VXL_VCL_FOUND "YES" ) # VXL vcl is always FOUND.  It is not optional.
SET(VXL_VCL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/vcl;/Users/Sean/Desktop/cs_project/vxl-tsai/vcl")
SET(VXL_VCL_LIBRARIES "vcl")

SET(VXL_CORE_FOUND "YES" ) # VXL core is always FOUND.  It is not optional.
SET(VXL_CORE_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core;/Users/Sean/Desktop/cs_project/vxl-tsai/core")
# VXL core has many libraries

SET(VXL_CORE_VIDEO_FOUND "YES" )
SET(VXL_CORE_VIDEO_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/core;/Users/Sean/Desktop/cs_project/vxl-tsai/core")
SET(VXL_CORE_VIDEO_LIBRARIES "vidl")

SET(VXL_VGUI_FOUND "NO")
SET(VXL_VGUI_INCLUDE_DIR "")
SET(VXL_VGUI_LIBRARIES "vgui")

SET(VXL_VGUI_WX_FOUND "")

SET(VXL_CONTRIB_FOUND "OFF")
# VXL contrib has subdirectories handled independently below
# VXL contrib has many libraries

SET(VXL_BRL_FOUND "OFF")
SET(VXL_BRL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/brl/bbas;/Users/Sean/Desktop/cs_project/vxl-tsai-codeblocks-bin/contrib/brl/bbas;/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/brl/bseg;/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/brl/bpro;/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/brl")
# VXL BRL has many libraries

SET(VXL_BGUI3D_FOUND "")
SET(VXL_BGUI3D_INCLUDE_DIR "")

SET(VXL_COIN3D_FOUND "")
SET(VXL_COIN3D_INCLUDE_DIR "")

SET(VXL_GEL_FOUND "OFF")
SET(VXL_GEL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/gel")
# VXL GEL has many libraries

SET(VXL_MUL_FOUND "OFF")
SET(VXL_MUL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/mul")
# VXL MUL has many libraries

SET(VXL_OUL_FOUND "OFF")
SET(VXL_OUL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/oul")
# VXL OUL has many libraries

SET(VXL_OXL_FOUND "OFF")
SET(VXL_OXL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/oxl")
# VXL OXL has many libraries

SET(VXL_RPL_FOUND "OFF")
SET(VXL_RPL_RGTL_FOUND "OFF")
SET(VXL_RPL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/rpl")
# VXL RPL has many libraries

SET(VXL_TBL_FOUND "OFF")
SET(VXL_TBL_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/tbl")
# VXL TBL has many libraries

SET(VXL_CONVERSIONS_FOUND "OFF")
SET(VXL_CONVERSIONS_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/contrib/conversions")
# VXL CONVERSIONS has no libraries

SET(VXL_TARGETJR_FOUND "")

# Client projects use these setting to find and use the 3rd party
# libraries that VXL either found on the system or built for itself.
# Sometimes, VXL will point client projects to the library VXL built
# for itself, and sometimes VXL will point client projects to the
# system library it found.

SET(VXL_NETLIB_FOUND "YES")
SET(VXL_NETLIB_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/v3p/netlib")
SET(VXL_NETLIB_LIBRARIES "netlib;v3p_netlib")

SET(VXL_QV_FOUND "YES")
SET(VXL_QV_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/v3p")
SET(VXL_QV_LIBRARIES "Qv")

SET(VXL_ZLIB_FOUND "TRUE")
SET(VXL_ZLIB_INCLUDE_DIR "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/usr/include")
SET(VXL_ZLIB_LIBRARIES "/usr/lib/libz.dylib")

SET(VXL_PNG_FOUND "YES")
SET(VXL_PNG_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/v3p/png;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/usr/include")
SET(VXL_PNG_LIBRARIES "png")

SET(VXL_JPEG_FOUND "YES")
SET(VXL_JPEG_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/v3p/jpeg")
SET(VXL_JPEG_LIBRARIES "jpeg")

SET(VXL_TIFF_FOUND "YES")
SET(VXL_TIFF_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/v3p/tiff")
SET(VXL_TIFF_LIBRARIES "tiff")

SET(VXL_GEOTIFF_FOUND "YES")
SET(VXL_GEOTIFF_INCLUDE_DIR "/Users/Sean/Desktop/cs_project/vxl-tsai/v3p/geotiff")
SET(VXL_GEOTIFF_LIBRARIES "geotiff")

SET(VXL_MPEG2_FOUND "")
SET(VXL_MPEG2_INCLUDE_DIR "")
SET(VXL_MPEG2_LIBRARIES "")

SET(VXL_RPLY_FOUND "")
SET(VXL_RPLY_INCLUDE_DIR "")
SET(VXL_RPLY_LIBRARIES "")

SET(VXL_COIN3D_FOUND "")
SET(VXL_COIN3D_INCLUDE_DIR "")
SET(VXL_COIN3D_LIBRARY "")

SET(VXL_PYTHON_FOUND "YES")
SET(VXL_PYTHON_INCLUDE_PATH "")
SET(VXL_PYTHON_PC_INCLUDE_PATH "")
SET(VXL_PYTHON_LIBRARY "/Library/Frameworks/Python.framework/Versions/3.5/lib/libpython3.5m.dylib")
SET(VXL_PYTHON_DEBUG_LIBRARY "")

SET(VXL_EXPAT_FOUND "TRUE")
SET(VXL_EXPAT_INCLUDE_DIR "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/usr/include")
SET(VXL_EXPAT_LIBRARIES "/usr/lib/libexpat.dylib")

# Tell UseVXL.cmake that VXLConfig.cmake has been included.
SET(VXL_CONFIG_CMAKE 1)

### deprecated variables set below ###
# These should be removed after some time to upgrade has passed.

# VXL include directories.
# There is no need for clients to use this directly
SET(VXL_V3P_INCLUDE_DIR_deprecated "/Users/Sean/Desktop/cs_project/vxl-tsai/v3p")

# Would a client project need to use these variables ever?
# These are needed for backward compatibility mode for now, see UseVXL.cmake
SET(VXL_VGUI_USE_GLUT_deprecated "")
SET(VXL_VGUI_USE_QT_deprecated "")
SET(VXL_VGUI_USE_MFC_deprecated "")
SET(VXL_VGUI_USE_GTK_deprecated "")
SET(VXL_VGUI_USE_GTK2_deprecated "")

# There is no need for clients to know this.
# These are needed for backward compatibility mode for now, see UseVXL.cmake
SET(VXL_FORCE_V3P_ZLIB_deprecated "OFF")
SET(VXL_FORCE_V3P_JPEG_deprecated "OFF")
SET(VXL_FORCE_V3P_TIFF_deprecated "OFF")
SET(VXL_FORCE_V3P_GEOTIFF_deprecated "OFF")
SET(VXL_FORCE_V3P_PNG_deprecated "OFF")
SET(VXL_FORCE_V3P_MPEG2_deprecated "")
SET(VXL_FORCE_V3P_RPLY_deprecated "")

