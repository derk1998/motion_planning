
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

    template <typename T, std::size_t N>
    Vertex<T, N>::Vertex(const T& x, const T& y) : point(x, y)
    {
        static_assert(N == 2, "XY constructor only usable in 2D");
    }

    template <typename T, std::size_t N>
    Vertex<T, N>::Vertex(const T& x, const T& y, const T& z) : point(x, y, z)
    {
        static_assert(N == 3, "XYZ constructor only usable in 3D");
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

    template <typename T, std::size_t D>
    void Vertex<T, D>::setActualCost(double cost)
    {
        actualCost = cost;
    }
    
    template <typename T, std::size_t D>
    void Vertex<T, D>::setHeuristicCost(double cost)
    {
        heuristicCost = cost;
    }

    template <typename T, std::size_t D>
    double Vertex<T, D>::calculateCost(const Vertex<T, D>& rhs)
    {
        double sum = 0;
        for(std::size_t i = 0; i < D; ++i)
            sum += std::pow(point[i] - rhs.point[i], 2);
        return std::sqrt(sum);
    }

    template <typename T, std::size_t D>
    void Vertex<T, D>::updateHeuristicCost(const Vertex<T, D>& rhs)
    {
        heuristicCost = actualCost + calculateCost(rhs);
    }

    template <typename T, std::size_t D>
    double Vertex<T, D>::getActualCost() const
    {
        return actualCost;
    }

    template <typename T, std::size_t D>
    double Vertex<T, D>::getHeuristicCost() const
    {
        return heuristicCost;
    }
}