namespace Base
{
    template <typename T, std::size_t D>
    Edge<T, D>::Edge(const Vertex<T, D>& v1_, const Vertex<T, D>& v2_) : v1(v1_), v2(v2_)
    {
    }

    template <typename T, std::size_t D>
    bool Edge<T, D>::operator<(const Edge<T, D>& rhs) const
    {
        return v1 < rhs.v1 || (v1 == rhs.v1 && v2 < rhs.v2);
    }

    template <typename T, std::size_t D>
    const Vertex<T, D> Edge<T, D>::getFrom() const
    {
        return v1;
    }

    template <typename T, std::size_t D>
    const Vertex<T, D> Edge<T, D>::getTo() const
    {
        return v2;
    }
}