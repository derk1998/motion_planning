
namespace Base
{
    template <typename T, std::size_t D>
    Box<T, D>::Box(const Point<T, D>& p1, const Point<T, D>& p2) : points{p1, p2}
    {
    }

    template <typename T, std::size_t D>
    Box<T, D>::Box() : points{Point<T, D>(), Point<T, D>()}
    {
    }

    template <typename T, std::size_t D>
    Box<T, D>::Box(const Box<T, D>& otherBox) : points{otherBox.points}
    {
    }

    template <typename T, std::size_t D>
    Box<T, D>::Box(Box<T, D>&& otherBox) : points{std::move(otherBox.points)}
    {
    }

    template <typename T, std::size_t D>
    Box<T, D>& Box<T, D>::operator=(const Box<T, D>& rhs)
    {
        if(this != &rhs)
        {
            points = rhs.points;
        }
        return *this;
    }

    template <typename T, std::size_t D>
    Box<T, D>& Box<T, D>::operator=(Box<T, D>&& rhs)
    {
        if(this != &rhs)
        {
            points = std::move(rhs.points);
        }
        return *this;
    }

    template <typename T, std::size_t D>
    bool Box<T, D>::isCorner(const Point<T, D>& point) const
    {
        auto points_ = getPoints();
        for(const auto& p : points_)
        {
            if(p == point) return true;
        }
        return false;
    }

    template <typename T, std::size_t D>
    std::array<Point<T, D>, 1 << D > Box<T, D>::getPoints() const
    {
        Point<T, D> left = points[0] < points[1] ? points[0] : points[1];
        Point<T, D> right = points[0] > points[1] ? points[0] : points[1];
        std::array<Point<T, D>, 1 << D > result;
        std::array<Point<T, D>, 2> tmpPoints{left, right};

        Point<T, D> tmpPoint;
        for(std::size_t i = 0; i < 1 << D; ++i)
        {
            for(std::size_t j = 0; j < D; ++j)
                tmpPoint[j] = tmpPoints[(i >> j) % 2][j];
            result[i] = tmpPoint;
        }

        return result;
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
    bool Box<T, D>::operator<(const Box<T, D>& rhs) const
    {
        return area() < rhs.area();
    }

    template <typename T, std::size_t D>
    Point<T, D> Box<T, D>::origin() const
    {
        Point<T, D> left = points[0] < points[1] ? points[0] : points[1];
        Point<T, D> right = (left == points[0]) ? points[1] : points[0];

        //if lefts y is smaller than rights y then left is origin for 2D
        //for 3D it is the z
        if(left[D-1] < right[D-1])
            return left;
        left[D-1] = right[D-1];
        return left;
    }

    template <typename T, std::size_t D>
    std::set<Edge<T, D>> Box<T, D>::createEdges(const Point<T, D>& point) const
    {
        std::set<Edge<T, D>> edges;
        auto vertices = getVertices();
        for(std::size_t i = 0; i < (1 << D); ++i)
        {
            auto vertex = Vertex<T, D>(point);
            if(vertices[i] != vertex)
                edges.insert(Edge(vertices[i], vertex));
        }
        return edges;
    }

    template <typename T, std::size_t D>
    std::set<Edge<T, D>> Box<T, D>::createEdges(const Box<T, D>& box) const
    {
        std::set<Edge<T, D>> edges;
        return edges;
    }

    template <typename T, std::size_t D>
    bool Box<T, D>::fits(const Box<T, D>& otherBox) const
    {
        Point<T, D> left = points[0] < points[1] ? points[0] : points[1];
        Point<T, D> right = (left == points[0]) ? points[1] : points[0];
        Point<T, D> rhsLeft = (otherBox[0] < otherBox[1]) ? otherBox[0] : otherBox[1];
        Point<T, D> rhsRight = (rhsLeft == otherBox[0]) ? otherBox[1] : otherBox[0];

        std::array<T, D> dimensions;
        std::array<T, D> dimensionsOtherBox;
        for(std::size_t i = 0; i < D; ++i)
        {
            dimensions[i] = right[i] - left[i];
            dimensionsOtherBox[i] = rhsRight[i] - rhsLeft[i];
        }

        bool result = true;
        Point<T, D> origin_ = origin();
        Point<T, D> rhsOrigin = otherBox.origin();
        for(std::size_t i = 0; i < D; ++i)
        {
            result = result && (rhsOrigin[i] + dimensionsOtherBox[i]) < (origin_[i] + dimensions[i]) && 
                (rhsOrigin[i] > origin_[i]);
        }
        return result;
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