lib_LTLIBRARIES = libbase.la
libbase_la_SOURCES =
libbase_la_CFLAGS = $(AM_CFLAGS) $(MOTION_PLANNING_CFLAGS)
libbase_la_CXXFLAGS = $(AM_CXXFLAGS) $(MOTION_PLANNING_CXXFLAGS)
include_HEADERS = include/Box.hpp \
                  include/Point.hpp \
                  include/Box.ipp \
                  include/Point.ipp
libbase_la_LDFLAGS = -version-info 0:0:0
libbase_la_DESTINATION = $(abs_srcdir)/$(lib_LTLIBRARIES)