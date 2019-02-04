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
        /**
         * @brief Creates a box with points of (0,0) or in 3D (0,0,0).
         * 
         */
        Box();

        /**
         * @brief Construct a box where p1 is the top left (and in 3D back) point and where p2 is the bottom right (and in 3D front) point.
         * 
         * @param p1 The top left (and in 3D back) point.
         * @param p2 The bottom right (and in 3D front) point.
         */
        explicit Box(const Point<T, D>& p1, const Point<T, D>& p2);

        /**
         * @brief Copy constructor.
         * 
         * @param otherBox The other box.
         */
        Box(const Box<T, D>& otherBox);

        /**
         * @brief Move constructor.
         * 
         * @param otherBox The other box.
         */
        Box(Box<T, D>&& otherBox);

        /**
         * @brief Checks if a point is a corner point of the box. 
         * 
         * @param point The point to be checked.
         * @return true If the point is a corner point.
         * @return false If the point is not a corner point.
         */
        bool isCorner(const Point<T, D>& point) const;

        /**
         * @brief Gets the points of the box.
         */
        std::array<Point<T, D>, 1 << D > getPoints() const;

        /**
         * @brief Assignment operator.
         * 
         * @param rhs 
         * @return Box<T, D>& 
         */
        Box<T, D>& operator=(const Box<T, D>& rhs);

        /**
         * @brief Move assigment operator.
         * 
         * @param rhs 
         * @return Box<T, D>& 
         */
        Box<T, D>& operator=(Box<T, D>&& rhs);

        /**
         * @brief Checks if a box fits in this box.
         * 
         * @param otherBox The other box.
         * @return true If the other box fits in this box.
         * @return false If the other box doesn't fit in this box.
         */
        bool fits(const Box<T, D>& otherBox) const;

        /**
         * @brief Checks if a point fits in this box.
         * 
         * @param point The point.
         * @return true If the point fits in this box.
         * @return false If the point doesn't fit in this box.
         */
        bool fits(const Point<T, D>& point) const;

        /**
         * @brief Subscript operator.
         * 
         * @param index 
         * @return Point<T, D>& 
         */
        Point<T, D>& operator[](std::size_t index);

        /**
         * @brief Less than operator.
         * 
         * @param rhs 
         * @return true 
         * @return false 
         */
        bool operator<(const Box<T, D>& rhs) const;

        T area() const;

        T length() const;

        T width() const;

        T depth() const;

        Point<T, D> origin() const;

        std::set<Edge<T, D>> getEdges() const;

        std::set<Edge<T, D>> createEdges(const Point<T, D>& point) const;
        std::set<Edge<T, D>> createEdges(const Box<T, D>& box) const;

        std::array<Vertex<T, D>, 1 << D > getVertices() const;

        const Point<T, D>& operator[](std::size_t index) const;
        private:
        std::array<Point<T, D>, 2> points;
    };

    template <typename T>
    using Box2D = Box<T, 2>;

    using Box2Ds = Box2D<std::size_t>;
    
    template <typename T>
    using Box3D = Box<T, 3>;
    
    using Box3Ds = Box3D<std::size_t>;
}

  template <typename T, std::size_t N> inline std::ostream &operator<<(std::ostream &os, const Base::Box<T, N>& rhs)
  {
    os << "{";
    os << rhs[0] << ", " << rhs[1];
    os << "}";
    return os;
  }

#include "Box.ipp"

#endif //BOX_HPP