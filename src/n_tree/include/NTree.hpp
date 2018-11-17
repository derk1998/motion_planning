#ifndef N_TREE_HPP
#define N_TREE_HPP

#include <memory>

#include <Box.hpp>
#include <NTreeElement.hpp>

template <typename T, std::size_t D>
class NTree
{
    public:
    NTree() = delete;
    explicit NTree(const Box<T, D>& aBox, NTree* parent = nullptr);
    NTree(const NTree&) = delete;
    NTree& operator=(const NTree&) = delete;
    ~NTree() = default;

    bool insert(const NTreeElement& element);

    const Box<T, D>& getBox() const;

    private:
    void clearChildren();
    void split();
    Box<T, D> box;
    std::array<std::unique_ptr<NTree>, 1 << D> children;
    NTree* parent;
    bool occupied;
    bool _split;
    std::vector<NTreeElement> elements;
};

template <typename T, std::size_t D> inline std::ostream &operator<<(std::ostream &os, const NTree<T, D>& rhs)
{
  return os << rhs.getBox()[0] << " -> " << rhs.getBox()[1];
}

template <typename T, std::size_t D> inline std::ostream &operator<<(std::ostream &os, const std::unique_ptr<NTree<T, D>>& rhs)
{
  return os << rhs->getBox()[0] << " -> " << rhs->getBox()[1];
}

#include "NTree.ipp"

#endif //N_TREE_HPP