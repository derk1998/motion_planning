#ifndef BOX_HPP
#define BOX_HPP

#include <array>

#include <Point.hpp>

template <typename T, std::size_t D>
class Box
{
    public:
    explicit Box(const Point<T, D>& p1, const Point<T, D>& p2);

    Point<T, D>& operator[](std::size_t index);

    bool fits(const Box<T, D>& otherBox) const;

    T area() const;

    T length() const;

    T width() const;

    T depth() const;

    const Point<T, D>& operator[](std::size_t index) const;
    private:
    std::array<Point<T, D>, 2> points;
};

#include "Box.ipp"

#endif //BOX_HPP