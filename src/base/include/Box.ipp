
namespace Base
{
    template <typename T, std::size_t D>
    Box<T, D>::Box(const Point<T, D>& p1, const Point<T, D>& p2) : points{p1, p2}
    {
    }

    template <typename T, std::size_t D>
    Point<T, D>& Box<T, D>::operator[](std::size_t index)
    {
        return points[index];
    }

    template <typename T, std::size_t D>
    const Point<T, D>& Box<T, D>::operator[](std::size_t index) const
    {
        return points[index];
    }

    template <typename T, std::size_t D>
    T Box<T, D>::area() const
    {
        if constexpr(D == 2)
            return length() * width();
        else
            return length() * width() * depth();
    }

    template <typename T, std::size_t D>
    T Box<T, D>::length() const
    {
        return points[0].y() + points[1].y();
    }

    template <typename T, std::size_t D>
    T Box<T, D>::width() const
    {
        return points[0].x() + points[1].x();
    }

    template <typename T, std::size_t D>
    T Box<T, D>::depth() const
    {
        static_assert(D == 3, "Only available in 3D");
        return points[0].z() + points[1].z();
    }

    template <typename T, std::size_t D>
    bool Box<T, D>::fits(const Box<T, D>& otherBox) const
    {
        Point<T, D> left = points[0] < points[1] ? points[0] : points[1];
        Point<T, D> right = (left == points[0]) ? points[1] : points[0];
        Point<T, D> rhsLeft = (otherBox[0] < otherBox[1]) ? otherBox[0] : otherBox[1];
        Point<T, D> rhsRight = (rhsLeft == otherBox[0]) ? otherBox[1] : otherBox[0];
        return ((rhsLeft > left && rhsLeft < right) && (rhsRight > left && rhsRight < right));
    }

    template <typename T, std::size_t D>
    bool Box<T, D>::fits(const Point<T, D>& point) const
    {
        Point<T, D> left = points[0] < points[1] ? points[0] : points[1];
        Point<T, D> right = points[0] > points[1] ? points[0] : points[1];

        return (point >= left && point <= right);
    }

    template <typename T, std::size_t D>
    std::array<Vertex<T, D>, 1 << D > Box<T, D>::getVertices() const
    {
        Vertex<T, D> left = points[0] < points[1] ? Vertex<T, D>(points[0]) : Vertex<T, D>(points[1]);
        Vertex<T, D> right = points[0] > points[1] ? Vertex<T, D>(points[0]) : Vertex<T, D>(points[1]);
        std::array<Vertex<T, D>, 1 << D > result;
        std::array<Vertex<T, D>, 2> tmpVertices{left, right};

        Vertex<T, D> tmpVertice;
        for(std::size_t i = 0; i < 1 << D; ++i)
        {
            for(std::size_t j = 0; j < D; ++j)
                tmpVertice[j] = tmpVertices[(i >> j) % 2][j];
            result[i] = tmpVertice;
        }

        return result;
    }

    template <typename T, std::size_t D>
    std::set<Edge<T, D>> Box<T, D>::getEdges() const
    {
        std::set<Edge<T, D>> edges;
        auto vertices = getVertices();
        for(std::size_t i = 0; i < (1 << D) - 1; ++i)
        {
            for(std::size_t j = i + 1; j < 1 << D; ++j)
            {
                if(vertices[i] != vertices[j]) edges.insert(Edge(vertices[i], vertices[j]));
            }
        }
        return edges;
    }
}