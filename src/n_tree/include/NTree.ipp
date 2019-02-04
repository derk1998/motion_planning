#include <algorithm>

namespace NTree
{
    template <typename T, std::size_t D>
    NTree<T, D>::NTree(const Base::Box<T, D>& aBox, NTree* parent /* = nullptr*/) : box(aBox), parent(std::move(parent)), _split(false), _obstacle(false)
    {
    }
    
    template <typename T, std::size_t D>
    bool NTree<T, D>::insert(Element& element, bool obstacle /* = false */)
    {   
        //Check if element fits. Note that the function has to be implemented in the Box class.
        bool fits = std::visit([this](auto&& arg){return box.fits(arg);}, element);
        if(!fits)
        {
            if(!parent) throw std::runtime_error("The obstacle does not fit in this box and there is no parent box!");
            return false;
        }

        //Split if the element fits, the box hasn't been splitted and it is splittable.
        if(!_split) split();

        //Try to recursively insert the element to one of the children.
        for(auto& child : children)
        {
            if(!child) continue;
            if(child->insert(element)) return true;
        }

        //Delete the splitted boxes, we don't need them
        clearChildren();

        //Finally, add the element to the elements.
        elements.push_back(element);

        _obstacle = obstacle;
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
        for(auto& child : children)
        {
            if(!child) continue;
            child.reset();
        }
    }

    template <typename T, std::size_t D>
    void NTree<T, D>::split()
    {
        if(_split) return;
        Base::Point<T, D> center;
        T sum = 0;
        for(std::size_t i = 0; i < D; ++i)
        {
            sum = (box[0][i] + box[1][i]);
            if(sum > 1) center[i] = sum / calculateDividingFactor(sum);
            else
            {
                //Actually not split but this cannot be split any further!
                _split = true;
                return;
            }
        }
        createChildren(center);

        for(auto& rhs : children)
        {
            for(auto& lhs : children)
            {
                if(rhs == lhs) continue;
                
            }
        }

        _split = true;
    }

    template <typename T, std::size_t D>
    T NTree<T, D>::calculateDividingFactor(T sum) const
    {
        T dividingFactor = 2;
        if(isPrimeNumber(sum)) dividingFactor = sum;
        else
        {
            for(std::size_t j = 2; j < static_cast<std::size_t>(sum); ++j)
            {
                if((sum % j == 0))
                {
                    dividingFactor = j;
                    break;
                }
            }
        }
        return dividingFactor;
    }

    template <typename T, std::size_t D>
    void NTree<T, D>::createChildren(const Base::Point<T, D>& center)
    {
        Base::Point<T, D> tmpPoint;
        for(std::size_t i = 0; i < children.size(); ++i)
        {
            for(std::size_t j = 0; j < D; ++j)
                tmpPoint[j] = box[(i >> j) % 2][j];
            children[i] = std::make_unique<NTree<T, D>>(Base::Box(tmpPoint, center), this);
        }
    }

    template <typename T, std::size_t D>
    bool NTree<T, D>::isPrimeNumber(T number) const
    {
        for(std::size_t i = 2; i <= number/2; ++i)
        {
            if(number % i == 0) return false;
        }
        return true;
    }
}