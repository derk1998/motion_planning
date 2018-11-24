AM_CPPFLAGS = -isystem $(top_srcdir)/lib/gtest/include -I$(top_srcdir)/src/n_tree/include $(GTEST_CPPFLAGS)
AM_CXXFLAGS = $(GTEST_CXXFLAGS) $(libn_tree_la_CXXFLAGS)
AM_LDFLAGS = $(GTEST_LDFLAGS) $(GTEST_LIBS) \
	     $(top_builddir)/gtest/lib/libgtest_main.la \
	     $(top_builddir)/gtest/lib/libgtest.la \
		 $(libn_tree_la_DESTINATION)

# TESTS -- Programs run automatically by "make check"
# check_PROGRAMS -- Programs built by "make check" but not necessarily run
TESTS = 
check_PROGRAMS = 

TESTS += n_tree_test
check_PROGRAMS += n_tree_test
n_tree_test_SOURCES = NTree.cpp
n_tree_test_LDADD = $(libn_tree_la_DESTINATION)

TESTS += point_test
check_PROGRAMS += point_test
point_test_SOURCES = Point.cpp