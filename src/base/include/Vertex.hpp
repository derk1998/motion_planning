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

        explicit Vertex(const T& x, const T& y);
        explicit Vertex(const T& x, const T& y, const T& z);

        bool lessCost(const Vertex<T, D>& rhs) const;
        bool operator<(const Vertex<T, D>& rhs) const;
        bool operator==(const Vertex<T, D>& rhs) const;
        bool operator!=(const Vertex<T, D>& rhs) const;

        const Point<T, D>& getPoint() const;

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        void setActualCost(double cost);
        void setHeuristicCost(double cost);
        double calculateCost(const Vertex<T, D>& rhs);
        void updateHeuristicCost(const Vertex<T, D>& rhs);
        double getActualCost() const;
        double getHeuristicCost() const;

        private:
        Point<T, D> point;
        double actualCost;
        double heuristicCost;
    };
}

#include "Vertex.ipp"

#endif //VERTEX_HPP