#ifndef N_TREE_HPP
#define N_TREE_HPP

#include <memory>
#include <variant>
#include <set>

#include <Box.hpp>

namespace NTree
{
  template <typename T, std::size_t D>
  class NTree
  {
      public:
      using Element = std::variant<Base::Box<T, D>, Base::Point<T, D>>;
      NTree() = delete;
      explicit NTree(const Base::Box<T, D>& aBox, NTree* parent = nullptr);
      NTree(const NTree&) = delete;
      NTree& operator=(const NTree&) = delete;
      ~NTree() = default;

      bool insert(Element& element);

      const Base::Box<T, D>& getBox() const;

      std::set<Base::Vertex<T, D>> getVertices() const;

      std::set<Base::Edge<T, D>> getEdges() const;

      private:
      std::set<Base::Vertex<T, D>> getVertices(std::set<Base::Vertex<T, D>>& currentVertices) const;
      std::set<Base::Edge<T, D>> getEdges(std::set<Base::Edge<T, D>>& currentEdges) const;
      void clearChildren();
      void split();
      Base::Box<T, D> box;
      std::array<std::unique_ptr<NTree>, 1 << D> children;
      NTree* parent;
      bool _split;
      std::vector<Element> elements;
  };

  template <typename T, std::size_t D> inline std::ostream &operator<<(std::ostream &os, const NTree<T, D>& rhs)
  {
    return os << rhs.getBox()[0] << " -> " << rhs.getBox()[1];
  }

  template <typename T, std::size_t D> inline std::ostream &operator<<(std::ostream &os, const std::unique_ptr<NTree<T, D>>& rhs)
  {
    return os << rhs->getBox()[0] << " -> " << rhs->getBox()[1];
  }

  template<typename T>
  using QuadTree = NTree<T, 2>;

  template<typename T>
  using Octree = NTree<T, 3>;

  template<typename T>
  using QuadTreeElement = typename NTree<T, 2>::Element;

  template<typename T>
  using OctreeElement = typename NTree<T, 3>::Element;
}
#include "NTree.ipp"

#endif //N_TREE_HPP