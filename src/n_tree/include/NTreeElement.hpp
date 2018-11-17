#ifndef N_TREE_ELEMENT
#define N_TREE_ELEMENT


class NTreeElement
{
    public:
    NTreeElement() = default;
    ~NTreeElement() = default;
    explicit NTreeElement(const NTreeElement& otherElement) = default;
    NTreeElement& operator=(const NTreeElement& rhs) = default;

    bool fits();
};

#endif //N_TREE_ELEMENT