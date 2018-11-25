#ifndef EDGE_HPP
#define EDGE_HPP

#include <Point.hpp>

namespace Base
{
    template <typename T, std::size_t D>
    struct Edge
    {
        Edge() = delete;
        Edge(Point<T, D> p1_, Point<T, D> p2_) : p1(p1_), p2(p2_){};

        bool operator<(const Edge<T, D>& rhs) const
        {   
            return p1 < rhs.p1 || (p1 == rhs.p1 && p2 < rhs.p2);
        }

        Point<T, D> p1;
        Point<T, D> p2;
    };
}
#endif //EDGE_HPP

/*
if (u < e.u)
    result = true;
else if (e.u < u)
    result = false;
else
    result = (v < e.v);
    */