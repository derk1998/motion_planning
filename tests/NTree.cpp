#include <gtest/gtest.h>
#include <NTree.hpp>
#include <AStar.hpp>

TEST(NTreeSuite, test)
{
    Base::Point2D<std::size_t> tl;
    Base::Point2D<std::size_t> br(7, 5);

    NTree::QuadTree<std::size_t> nTree(Base::Box2D<std::size_t>(tl, br));
    Base::Box2D<std::size_t> box(Base::Point2D<std::size_t>(2,2), Base::Point2D<std::size_t>(4,4));
    Base::Box2D<std::size_t> box2(Base::Point2D<std::size_t>(6,3), Base::Point2D<std::size_t>(6,4));
    NTree::QuadTreeElement<std::size_t> boxElement = box;
    NTree::QuadTreeElement<std::size_t> box2Element = box2;

    nTree.insert(boxElement);
    // nTree.insert(box2Element);

    auto edges = nTree.getEdges();

    for(auto& edge : edges)
    {
      std::cout << "p1: " << edge.getFrom().getPoint() << " p2: " << edge.getTo().getPoint() << std::endl;
    }

    Pathfinding::AStar<std::size_t, 2> AStar;
    auto path = AStar.search(Base::Vertex<std::size_t, 2>(0,0), Base::Vertex<std::size_t, 2>(7,5), edges);

    std::cout << "PATH: " << std::endl;
    for(auto& node : path)
    {
      std::cout << node.getPoint() << std::endl;
    }

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}