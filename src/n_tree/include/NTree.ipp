#include <algorithm>

namespace NTree
{
    template <typename T, std::size_t D>
    NTree<T, D>::NTree(const Base::Box<T, D>& aBox, NTree* parent /* = nullptr*/) : box(aBox), parent(std::move(parent)), _split(false)
    {
    }
    
    template <typename T, std::size_t D>
    bool NTree<T, D>::insert(Element& element)
    {   
        //Check if element fits. Note that the function has to be implemented in the Box class.
        bool fits = std::visit([this](auto&& arg){std::cout << "p1 arg: " << arg[0] << " p2 arg: " << arg[1] << std::endl; return box.fits(arg);}, element);
        std::cout << "p1 box: " << box[0] << " p2 box: " << box[1] << std::endl;
        if(!fits)
        {
            if(!parent) throw std::runtime_error("The obstacle does not fit in this box and there is no parent box!");
            return false;
        }
        std::cout << "FITS!" << std::endl;
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
        std::cout << "INSERTED: p1: " << std::get<Base::Box<T,D>>(element)[0] << " p2: " << std::get<Base::Box<T,D>>(element)[1] << std::endl;
        std::cout << "INTO: p1: " << box[0] << " p2: " << box[1] << std::endl;
        bool res = std::visit([this](auto&& arg){std::cout << "p1 arg: " << arg[0] << " p2 arg: " << arg[1] << std::endl; return box.fits(arg);}, element);
        std::cout << "RES: " << res << std::endl;
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
            if(!child) continue;
            std::cout << "Child: p1" << child->box[0] << " p2: " << child->box[1] << std::endl;
            child.reset();
        }
    }

    template <typename T, std::size_t D>
    std::set<Base::Vertex<T, D>> NTree<T, D>::getVertices() const
    {
        std::set<Base::Vertex<T, D>> vertices;
        return getVertices(vertices);
    }

    template <typename T, std::size_t D>
    std::set<Base::Vertex<T, D>> NTree<T, D>::getVertices(std::set<Base::Vertex<T, D>>& currentVertices) const
    {
        //Get the vertices of this box
        auto vertices = box.getVertices();
        currentVertices.insert(std::begin(vertices), std::end(vertices));

        //Get vertices of each child
        for(auto& child : children)
        {
            if(!child) continue;
            currentVertices = child->getVertices(currentVertices);
        }
        return currentVertices;
    }

    template <typename T, std::size_t D>
    std::set<Base::Edge<T, D>> NTree<T, D>::getEdges() const
    {
        std::set<Base::Edge<T, D>> edges;
        return getEdges(edges);
    }

    template <typename T, std::size_t D>
    std::set<Base::Edge<T, D>> NTree<T, D>::getEdges(std::set<Base::Edge<T, D>>& currentEdges) const
    {
        //Get the edges of this box if it is the deepest level and it contains no elements
        if(!_split && elements.size() == 0)
        {
            auto edges = box.getEdges();
            currentEdges.insert(std::begin(edges), std::end(edges));
        }

        //Get vertices of each child
        for(auto& child : children)
        {
            if(!child) continue;
            currentEdges = child->getEdges(currentEdges);
        }
        return currentEdges;
    }

    template <typename T, std::size_t D>
    void NTree<T, D>::split()
    {
        Base::Point<T, D> center;
        T sum = 0;
        T dividingFactor = 2;
        for(std::size_t i = 0; i < D; ++i)
        {
            sum = (box[0][i] + box[1][i]);
            if(sum > 1)
            {
                //choose dividing factor
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
                center[i] = sum / dividingFactor;
            }
            else
            {
                //Actually not split but this cannot be split any further!
                _split = true;
                return;
            }
        }

        Base::Point<T, D> tmpPoint;
        for(std::size_t i = 0; i < children.size(); ++i)
        {
            for(std::size_t j = 0; j < D; ++j)
                tmpPoint[j] = box[(i >> j) % 2][j];
            children[i] = std::make_unique<NTree<T, D>>(Base::Box(tmpPoint, center), this);
        }
        _split = true;
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