
namespace Base
{
    template <typename T, std::size_t D>
    Vertex<T, D>::Vertex(const Point<T, D>& p) : point(p), actualCost(0.0), heuristicCost(0.0)
    {
    }

    template <typename T, std::size_t D>
    Vertex<T, D>::Vertex() : point(), actualCost(0.0), heuristicCost(0.0)
    {
    }

    template <typename T, std::size_t D>
    bool Vertex<T, D>::lessCost(const Vertex<T, D>& rhs) const
    {
        if(heuristicCost < rhs.heuristicCost) return true;
        if(heuristicCost == rhs.heuristicCost) return actualCost > rhs.actualCost;
        return false;
    }

    template <typename T, std::size_t D>
    bool Vertex<T, D>::operator<(const Vertex<T, D>& rhs) const
    {
        return point < rhs.point;
    }

    template <typename T, std::size_t D>
    bool Vertex<T, D>::operator==(const Vertex<T, D>& rhs) const
    {
        return point == rhs.point;
    }

    template <typename T, std::size_t D>
    bool Vertex<T, D>::operator!=(const Vertex<T, D>& rhs) const
    {
        return point != rhs.point;
    }

    template <typename T, std::size_t D>
    const Point<T, D>& Vertex<T, D>::getPoint() const
    {
        return point;
    }

    template <typename T, std::size_t D>
    T& Vertex<T, D>::operator[](std::size_t index)
    {
        return point[index];
    }

    template <typename T, std::size_t D>
    const T& Vertex<T, D>::operator[](std::size_t index) const
    {
        return point[index];
    }
}