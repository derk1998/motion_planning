#include <cassert>
#include <type_traits>
#include <cmath>

namespace Base
{
  template <typename T, std::size_t N>
  Point<T, N>::Point(T value /* = 0 */)
  {
    static_assert(N > 1, "Point has to contain at least 2 dimensions");
    data.fill(value);
  }

  template <typename T, std::size_t N>
  Point<T, N>::Point(const T& x, const T& y) : data{x, y}
  {
    static_assert(N == 2, "XY constructor only usable in 2D");
  }

  template <typename T, std::size_t N>
  Point<T, N>::Point(const T& x, const T& y, const T& z) : data{x, y, z}
  {
    static_assert(N == 3, "XYZ constructor only usable in 3D");
  }

  template <typename T, std::size_t N>
  Point<T, N>::Point(const Point<T, N>& otherPoint) : data(otherPoint.data)
  {
  }

  template <typename T, std::size_t N>
  Point<T, N>::Point(Point<T, N>&& otherPoint) : data(std::move(otherPoint.data))
  {
  }

  template <typename T, std::size_t N>
  bool Point<T, N>::operator<(const Point<T, N>& rhs) const
  {
    if(&rhs == this) return false;
    for(std::size_t i = 0; i < N - 1; ++i)
      if(data[i] != rhs.data[i]) return data[i] < rhs.data[i];
    return data[N-1] < rhs.data[N-1];
  }

  template <typename T, std::size_t N>
  bool Point<T, N>::operator<=(const Point<T, N>& rhs) const
  {
    bool equal = operator==(rhs);
    if(!equal) return operator<(rhs);
    return equal;
  }

  template <typename T, std::size_t N>
  bool Point<T, N>::operator==(const Point<T, N>& rhs) const
  {
    if(&rhs == this) return true;
    if constexpr (std::is_integral_v<T>)
    {
      for(std::size_t i = 0; i < N; ++i)
        if(data[i] != rhs.data[i]) return false;
    }
    else if(std::is_floating_point_v<T>)
    {
      for(std::size_t i = 0; i < N; ++i)
      if(!(std::abs(data[i] - rhs.data[i]) <= std::numeric_limits<T>::epsilon() * std::abs(data[i] + rhs.data[i])
      || std::abs(data[i] - rhs.data[i]) < std::numeric_limits<T>::min())) return false;
    }
    return true;
  }

  template <typename T, std::size_t N>
  bool Point<T, N>::operator!=(const Point<T, N>& rhs) const
  {
    return !operator==(rhs);
  }

  template <typename T, std::size_t N>
  bool Point<T, N>::operator>(const Point<T, N>& rhs) const
  {
    if(&rhs == this) return false;
    for(std::size_t i = N - 1; i > 0; --i)
      if(data[i] != rhs.data[i]) return data[i] > rhs.data[i];
    return data[0] > rhs.data[0];
  }

  template <typename T, std::size_t N>
  bool Point<T, N>::operator>=(const Point<T, N>& rhs) const
  {
    bool equal = operator==(rhs);
    if(!equal) return operator>(rhs);
    return equal;
  }

  template <typename T, std::size_t N>
  const T& Point<T, N>::x() const
  {
    return data[0];
  }

  template <typename T, std::size_t N>
  const T& Point<T, N>::y() const
  {
    static_assert(N >= 2, "y method not usable in 1D");
    return data[1];
  }

  template <typename T, std::size_t N>
  const T& Point<T, N>::z() const
  {
    static_assert(N == 3, "z method only usable in 3D");
    return data[2];
  }

  template <typename T, std::size_t N>
  T& Point<T, N>::operator[](std::size_t index)
  {
    assert(index < N);
    return data[index];
  }

  template <typename T, std::size_t N>
  const T& Point<T, N>::operator[](std::size_t index) const
  {
    assert(index < N);
    return data[index];
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator+(const Point<T, N>& rhs) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] + rhs.data[i]);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator+(const T& scalar) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] + scalar);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator-(const Point<T, N>& rhs) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] - rhs.data[i]);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator-(const T& scalar) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] - scalar);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator*(const Point<T, N>& rhs) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] * rhs.data[i]);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator*(const T& scalar) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] * scalar);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator/(const Point<T, N>& rhs) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] / rhs.data[i]);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N> Point<T, N>::operator/(const T& scalar) const
  {
    Point<T, N> result;
    for(std::size_t i = 0; i < N; ++i)
      result[i] = (data[i] / scalar);
    return result;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator+=(const Point<T, N>& rhs)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] += rhs.data[i];
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator=(const Point<T, N>& rhs)
  {
    if(this != &rhs)
      data = rhs.data;
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator=(Point<T, N>&& rhs)
  {
    if(this != &rhs)
      data = std::move(rhs.data);
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator+=(const T& scalar)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] += scalar;
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator-=(const Point<T, N>& rhs)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] -= rhs.data[i];
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator-=(const T& scalar)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] -= scalar;
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator*=(const Point<T, N>& rhs)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] *= rhs.data[i];
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator*=(const T& scalar)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] *= scalar;
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator/=(const Point<T, N>& rhs)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] /= rhs.data[i];
    return *this;
  }

  template <typename T, std::size_t N>
  Point<T, N>& Point<T, N>::operator/=(const T& scalar)
  {
    for(std::size_t i = 0; i < N; ++i)
      data[i] /= scalar;
    return *this;
  }

  template <typename T, std::size_t N>
  const T& Point<T, N>::get(std::size_t index) const
  {
    assert(index < N);
    return data[index];
  }

  template <typename T, std::size_t N>
  void Point<T, N>::set(std::size_t index, const T& value)
  {
    assert(index < N);
    data[index] = value;
  }

  template <typename T, std::size_t N>
  const T Point<T, N>::dotProduct(const Point<T, N>& rhs) const
  {
    T sum = 0;
    for(std::size_t i = 0; i < N; ++i)
      sum += (data[i] * rhs.data[i]);
    return sum;
  }

  template <typename T, std::size_t N>
  const T Point<T, N>::magnitude() const
  {
    T sum = 0;
    for(std::size_t i = 0; i < N; ++i)
      sum += std::pow(data[i], 2);
    return std::sqrt(sum);
  }

  template <typename T, std::size_t N>
  const T Point<T, N>::cosineSim(const Point<T, N>& rhs) const
  {
    return dotProduct(rhs) / (magnitude() * rhs.magnitude());
  }
}