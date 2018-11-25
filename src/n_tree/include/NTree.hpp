#ifndef N_TREE_HPP
#define N_TREE_HPP

#include <memory>
#include <variant>

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

      std::vector<Base::Point<T, D>> getVertices() const;

      private:
      std::vector<Base::Point<T, D>> getVertices(std::vector<Base::Point<T, D>>& currentVertices) const;
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
}
#include "NTree.ipp"

#endif //N_TREE_HPP