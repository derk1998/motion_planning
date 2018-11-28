lib_LTLIBRARIES = libpathfinding.la
libpathfinding_la_SOURCES = 
libpathfinding_la_CFLAGS = $(AM_CFLAGS) $(MOTION_PLANNING_CFLAGS) -I$(srcdir)/include
libpathfinding_la_CXXFLAGS = $(AM_CXXFLAGS) $(MOTION_PLANNING_CXXFLAGS) -I$(srcdir)/include
include_HEADERS = include/AStar.hpp \
                  include/AStar.ipp
libpathfinding_la_LDFLAGS = -version-info 0:0:0
libpathfinding_la_LIBADD = $(AM_LIBADD) $(libbase_la_DESTINATION)
libpathfinding_la_DEPENDENCIES = $(libbase_la_DESTINATION)
libpathfinding_la_DESTINATION = $(abs_srcdir)/$(lib_LTLIBRARIES)