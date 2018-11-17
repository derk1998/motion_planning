#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([MotionPlanning], [1.0.0], [derkwiegerinck@gmail.com])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AM_PROG_LIBTOOL
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for header files.

AC_HEADER_STDC

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([pow sqrt])

#########################################################################################################
#                     Set the preprocessor, c-compiler, c++-compiler and linker option
#########################################################################################################

# set the CPP options
case $host in
*linux*)
	MOTION_PLANNING_CPPFLAGS=""
	;;
*mingw* | *i686-pc-mingw64* | *i686-pc-mingw32* | *i686-pc-msys* | *x86_64-unknown-msys*)
	MOTION_PLANNING_CPPFLAGS="-D_WIN32_WINNT=0x0501"
	;;
*darwin*)
	MOTION_PLANNING_CPPFLAGS=""
	;;
esac
AC_SUBST([MOTION_PLANNING_CPPFLAGS])

# set the C options
case $host in
*linux*)
	MOTION_PLANNING_CFLAGS="-pipe -std=gnu17"
	;;
*mingw* | *i686-pc-mingw64* | *i686-pc-mingw32* | *i686-pc-msys* | *x86_64-unknown-msys*)
	MOTION_PLANNING_CFLAGS="-pipe -std=gnu17"
	;;
*darwin*)
	MOTION_PLANNING_CFLAGS="-pipe -std=gnu17"
	;;
esac
AC_SUBST([MOTION_PLANNING_CFLAGS])

# set the C++ options
case $host in
*linux*)
	MOTION_PLANNING_CXXFLAGS="-pipe -std=gnu++17"
	;;
*mingw* | *i686-pc-mingw64* | *i686-pc-mingw32* | *i686-pc-msys* | *x86_64-unknown-msys*)
	MOTION_PLANNING_CXXFLAGS="-pipe -std=gnu++17"
	;;
*darwin*)
	MOTION_PLANNING_CXXFLAGS="-pipe -std=gnu++17"
	;;
esac
AC_SUBST([MOTION_PLANNING_CXXFLAGS])

# set the Linker options
case $host in
*linux*)
	MOTION_PLANNING_LDFLAGS=""
	;;
*mingw* | *i686-pc-mingw64* | *i686-pc-mingw32* | *i686-pc-msys* | *x86_64-unknown-msys*)
	MOTION_PLANNING_LDFLAGS="-Wl,--subsystem,windows -mwindows"
	;;
*darwin*)
	MOTION_PLANNING_LDFLAGS=""
	;;
	
esac
AC_SUBST([MOTION_PLANNING_LDFLAGS])

AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 examples/Makefile
                 man/Makefile
                 scripts/Makefile
                 src/Makefile
                 src/base/Makefile
                 src/app/Makefile
                 src/n_tree/Makefile])
AC_OUTPUT