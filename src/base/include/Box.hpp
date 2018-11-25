#ifndef BOX_HPP
#define BOX_HPP

#include <array>

#include <Point.hpp>

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

        std::array<Point<T, D>, 1 << D > getPoints() const;

        const Point<T, D>& operator[](std::size_t index) const;
        private:
        std::array<Point<T, D>, 2> points;
    };
}
#include "Box.ipp"

#endif //BOX_HPP