#include <gtest/gtest.h>
#include <NTree.hpp>
#include <AStar.hpp>

TEST(NTreeSuite, test)
{
    Base::Point2D<std::size_t> tl;
    Base::Point2D<std::size_t> br(7, 5);

    NTree::QuadTree<std::size_t> nTree(Base::Box2D<std::size_t>(tl, br));
    Base::Box2D<std::size_t> box(Base::Point2D<std::size_t>(0,0), Base::Point2D<std::size_t>(2,2));
    Base::Box2D<std::size_t> box2(Base::Point2D<std::size_t>(6,3), Base::Point2D<std::size_t>(7,5));
    NTree::QuadTreeElement<std::size_t> boxElement = box;
    NTree::QuadTreeElement<std::size_t> box2Element = box2;

    nTree.insert(boxElement);

    auto vertices = nTree.getVertices();
    for(auto vertice : vertices)
    {
      std::cout << vertice.getPoint() << std::endl;
    }

    auto edges = nTree.getEdges();
    for(auto edge : edges)
    {
      std::cout << edge.getFrom().getPoint() << "\t->\t" << edge.getTo().getPoint() << std::endl;
    }

    Pathfinding::AStar<std::size_t, 2> AStar;
    auto path = AStar.search(Base::Vertex<std::size_t, 2>(0,0), Base::Vertex<std::size_t, 2>(7,2), edges);

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