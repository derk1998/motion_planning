#ifndef BOX_HPP
#define BOX_HPP

#include <array>
#include <set>

#include <Point.hpp>
#include <Edge.hpp>

namespace Base
{
    template <typename T, std::size_t D>
    class Box
    {
        public:
        explicit Box(const Point<T, D>& p1, const Point<T, D>& p2);

        bool fits(const Box<T, D>& otherBox) const;

        bool fits(const Point<T, D>& point) const;

        Point<T, D>& operator[](std::size_t index);

        T area() const;

        T length() const;

        T width() const;

        T depth() const;

        std::set<Edge<T, D>> getEdges() const;

        std::array<Vertex<T, D>, 1 << D > getVertices() const;

        const Point<T, D>& operator[](std::size_t index) const;
        private:

        std::array<Point<T, D>, 2> points;
    };

    template <typename T>
    using Box2D = Box<T, 2>;
    
    template <typename T>
    using Box3D = Box<T, 3>;
}
#include "Box.ipp"

#endif //BOX_HPP