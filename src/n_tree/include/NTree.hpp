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
      /**
       * @brief NTree element that can either be a box or a point.
       * 
       */
      using Element = std::variant<Base::Box<T, D>, Base::Point<T, D>>;

      /**
       * @brief No default constructor.
       * 
       */
      NTree() = delete;

      /**
       * @brief Creates a NTree.
       * 
       * @param aBox The underlying box of the tree. The dimensions of the tree are the same as those of the box.
       * @param parent The parent of the tree.
       */
      explicit NTree(const Base::Box<T, D>& aBox, NTree* parent = nullptr);

      /**
       * @brief No copy constructor.
       * 
       */
      NTree(const NTree&) = delete;

      /**
       * @brief No copy assignment.
       * 
       * @return NTree& 
       */
      NTree& operator=(const NTree&) = delete;

      /**
       * @brief Default destructor.
       * 
       */
      ~NTree() = default;

      /**
       * @brief Inserts an element to tree.
       * 
       * @param element The element to be inserted.
       * @param obstacle True if the element is an obstacle.
       * @return true If the element has successfully been inserted.
       * @return false If the element could not be inserted.
       */
      bool insert(Element& element, bool obstacle = false);

      /**
       * @brief Gets the underlying box.
       * 
       * @return const Base::Box<T, D>& The box.
       */
      const Base::Box<T, D>& getBox() const;

      /**
       * @brief Gets the vertices of the tree.
       * 
       * @return std::set<Base::Vertex<T, D>> The vertices.
       */
      std::set<Base::Vertex<T, D>> getVertices() const;

      /**
       * @brief Gets the edges of the tree.
       * 
       * @return std::set<Base::Edge<T, D>> The edges. 
       */
      std::set<Base::Edge<T, D>> getEdges() const;

      private:
      /**
       * @brief Calculates a dividing factor to split the box.
       * 
       * @param sum The sum of one dimension of two boxes. For instance the x of box 1 and the x of box 2.
       * @return T The dividing factor.
       */
      T calculateDividingFactor(T sum) const;

      /**
       * @brief Creates the children of this tree.
       * 
       * @param center The center of the tree.
       */
      void createChildren(const Base::Point<T, D>& center);

      /**
       * @brief Checks if a number is a prime number.
       * 
       * @param number The number to be checked.
       * @return true If the number is a prime number.
       * @return false If the number is not a prime number.
       */
      bool isPrimeNumber(T number) const;

      /**
       * @brief Clears the children from the tree.
       * 
       */
      void clearChildren();

      /**
       * @brief Splits the tree in 4 trees in 2D and 8 trees in 4D.
       * The created trees are children of this tree.
       * 
       */
      void split();

      Base::Box<T, D> box;
      std::array<std::unique_ptr<NTree>, 1 << D> children;
      NTree* parent;
      bool _split;
      bool _obstacle;
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