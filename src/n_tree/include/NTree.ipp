#include <algorithm>

namespace NTree
{
    template <typename T, std::size_t D>
    NTree<T, D>::NTree(const Base::Box<T, D>& aBox, NTree* parent /* = nullptr*/) : box(aBox), parent(std::move(parent)), _split(false)
    {
    }
    
    //neighbour checking

    /*

    find cell of S
    add cell to set

    */
    template <typename T, std::size_t D>
    bool NTree<T, D>::insert(Element& element)
    {   
        //Check if element fits. Note that the function has to be implemented in the Box class.
        bool fits = std::visit([this](auto&& arg){return box.fits(arg);}, element);
        if(!fits)
        {
            if(!parent) throw std::runtime_error("The obstacle does not fit in this box and there is no parent box!");
            return false;
        }
        //Split if the element fits, the box hasn't been splitted and it is splittable.
        if(!_split && box.area() >= (1 << D)) split();

        //Try to recursively insert the element to one of the children.
        for(auto& child : children)
        {
            if(!child) continue;
            if(child->insert(element)) return true;
        }

        //Finally, add the element to the elements.
        elements.push_back(element);
        return true;
    }

    template <typename T, std::size_t D>
    const Base::Box<T, D>& NTree<T, D>::getBox() const
    {
        return box;
    }

    template <typename T, std::size_t D>
    void NTree<T, D>::clearChildren()
    {
        std::cout << "Clearing children..." << std::endl;
        for(auto& child : children)
        {
            child.reset();
        }
    }

    template <typename T, std::size_t D>
    void NTree<T, D>::split()
    {
        std::cout << "Split!" << std::endl;
        Base::Point<T, D> center;
        for(std::size_t i = 0; i < D; ++i)
            center[i] = (box[0][i] + box[1][i]) / 2;
            
        //2D
        //LT = p1.x, p1.y
        //RT = p2.x, p1.y
        //LB = p1.x, p2.y
        //RB = p2.x, p2.y

        //3D
        //LTB = p1.x, p1.y, p1.z
        //RTB = p2.x, p1.y, p1.z
        //LBB = p1.x, p2.y, p1.z
        //RBB = p2.x, p2.y, p1.z
        //LTF = p1.x, p1.y, p2.z
        //RTF = p2.x, p1.y, p2.z
        //LBF = p1.x, p2.y, p2.z
        //RBF = p2.x, p2.y, p2.z

        Base::Point<T, D> tmpPoint;
        for(std::size_t i = 0; i < children.size(); ++i)
        {
            for(std::size_t j = 0; j < D; ++j)
                tmpPoint[j] = box[(i >> j) % 2][j];
            children[i] = std::make_unique<NTree<T, D>>(Base::Box(tmpPoint, center), this);
        }
        _split = true;
    }
}