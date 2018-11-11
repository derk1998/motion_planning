#include <gtest/gtest.h>
#include <NTree.hpp>

TEST(NTreeSuite, test)
{
    Point<std::size_t, 2> tl;
    Point<std::size_t, 2> br(7, 5);

    NTree<std::size_t, 2> nTree(Box<std::size_t, 2>(tl, br));
    Box<std::size_t, 2> box(Point<std::size_t, 2>(0,0), Point<std::size_t, 2>(2,2));
    Box<std::size_t, 2> box2(Point<std::size_t, 2>(6,3), Point<std::size_t, 2>(7,5));
    nTree.insert(box);
    nTree.insert(box2);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}