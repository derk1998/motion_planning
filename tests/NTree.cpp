#include <gtest/gtest.h>
#include <NTree.hpp>
#include <AStar.hpp>

TEST(NTreeSuite, test)
{
    Base::Point2D<std::size_t> tl;
    Base::Point2D<std::size_t> br(10, 10);

    NTree::QuadTree<std::size_t> nTree(Base::Box2D<std::size_t>(tl, br));
    Base::Box2D<std::size_t> box(Base::Point2D<std::size_t>(2,2), Base::Point2D<std::size_t>(4,4));
    Base::Box2D<std::size_t> box1a(Base::Point2D<std::size_t>(2,2), Base::Point2D<std::size_t>(3,3));
    Base::Box2D<std::size_t> box1b(Base::Point2D<std::size_t>(3,3), Base::Point2D<std::size_t>(4,4));
    Base::Box2D<std::size_t> box2(Base::Point2D<std::size_t>(6,3), Base::Point2D<std::size_t>(6,4));

    Base::Point2D<std::size_t> start = Base::Point2D<std::size_t>(0, 0);
    Base::Point2D<std::size_t> goal = Base::Point2D<std::size_t>(9, 9);

    NTree::QuadTreeElement<std::size_t> boxElement = box;
    NTree::QuadTreeElement<std::size_t> box1aElement = box1a;
    NTree::QuadTreeElement<std::size_t> box1bElement = box1b;
    NTree::QuadTreeElement<std::size_t> box2Element = box2;

    NTree::QuadTreeElement<std::size_t> startElement = start;
    NTree::QuadTreeElement<std::size_t> goalElement = goal;

    nTree.insert(boxElement);
    nTree.insert(box1aElement);
    // nTree.insert(box2Element);
    // nTree.insert(startElement);
    // nTree.insert(goalElement);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}