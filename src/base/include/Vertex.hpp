#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <Point.hpp>

namespace Base
{
    template <typename T, std::size_t D>
    class Vertex
    {
        public:
        explicit Vertex(const Point<T, D>& p);
        Vertex();

        bool lessCost(const Vertex<T, D>& rhs) const;
        bool operator<(const Vertex<T, D>& rhs) const;
        bool operator==(const Vertex<T, D>& rhs) const;
        bool operator!=(const Vertex<T, D>& rhs) const;

        const Point<T, D>& getPoint() const;

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        private:
        Point<T, D> point;
        double actualCost;
        double heuristicCost;
    };
}

#include "Vertex.ipp"

#endif //VERTEX_HPP