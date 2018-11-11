

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
    Point<T, D> right = points[0] > points[1] ? points[0] : points[1];

    return (otherBox.points[0] >= left && otherBox.points[0] <= right &&
       otherBox.points[1] >= left && otherBox.points[1] <= right);
}