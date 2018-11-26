#ifndef EDGE_HPP
#define EDGE_HPP

#include <Vertex.hpp>

namespace Base
{
    template <typename T, std::size_t D>
    struct Edge
    {
        Edge() = delete;
        Edge(const Vertex<T, D>& v1_, const Vertex<T, D>& v2_);

        bool operator<(const Edge<T, D>& rhs) const;

        const Vertex<T, D> getFrom() const;
        const Vertex<T, D> getTo() const;

        Vertex<T, D> v1;
        Vertex<T, D> v2;
    };
}

#include "Edge.ipp"

#endif //EDGE_HPP