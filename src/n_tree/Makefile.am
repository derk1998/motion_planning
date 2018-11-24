lib_LTLIBRARIES = libn_tree.la
libn_tree_la_SOURCES = src/NTreeElement.cpp
libn_tree_la_CFLAGS = $(AM_CFLAGS) $(MOTION_PLANNING_CFLAGS) -I$(srcdir)/include
libn_tree_la_CXXFLAGS = $(AM_CXXFLAGS) $(MOTION_PLANNING_CXXFLAGS) -I$(srcdir)/include
include_HEADERS = include/NTree.hpp \
                  include/NTree.ipp \
                  include/NTreeBox.hpp \
                  include/NTreePoint.hpp
libn_tree_la_LDFLAGS = -version-info 0:0:0
libn_tree_la_LIBADD = $(AM_LIBADD) $(libbase_la_DESTINATION)
libn_tree_la_DEPENDENCIES = $(libbase_la_DESTINATION)
libn_tree_la_DESTINATION = $(abs_srcdir)/$(lib_LTLIBRARIES)