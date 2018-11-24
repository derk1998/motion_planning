#include <gtest/gtest.h>
#include <NTree.hpp>

TEST(NTreeSuite, test)
{
    Base::Point<std::size_t, 2> tl;
    Base::Point<std::size_t, 2> br(7, 5);

    NTree::NTree<std::size_t, 2> nTree(Base::Box<std::size_t, 2>(tl, br));
    Base::Box<std::size_t, 2> box(Base::Point<std::size_t, 2>(0,0), Base::Point<std::size_t, 2>(2,2));
    Base::Box<std::size_t, 2> box2(Base::Point<std::size_t, 2>(6,3), Base::Point<std::size_t, 2>(7,5));
    NTree::NTree<std::size_t, 2>::Element boxElement = box;
    NTree::NTree<std::size_t, 2>::Element box2Element = box2;

    nTree.insert(boxElement);
    nTree.insert(box2Element);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}