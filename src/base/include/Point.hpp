#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>
#include <array>

namespace Base
{
  template <typename T, std::size_t N>
  class Point
  {
  public:
    /**
     * @name Constructors and destructor
     */
    //@{
    /**
     * @brief Default constructor that initializes the coordinates with the same value.
     * 
     * @param value A value to set the initial value of the coordinates. Default value is 0.
     */
    explicit Point(T value = 0);

    /**
     * @brief Constructor to set a 2D point with specific coordinates.
     * 
     * @param x The x coordinate.
     * @param y The y coordinate.
     */
    explicit Point(const T& x, const T& y);

    /**
     * @brief Constructor to set a 3D point with specific coordinates.
     * 
     * @param x The x coordinate.
     * @param y The y coordinate.
     * @param z The z coordinate.
     */
    explicit Point(const T& x, const T& y, const T& z);

    /**
     * @brief Copy constructor.
     * 
     * @param otherPoint The other point.
     */
    Point(const Point<T, N>& otherPoint);

    /**
     * @brief Move constructor.
     * 
     * @param otherPoint The other point.
     */
    Point(Point<T, N>&& otherPoint);

    /**
     * @brief Destructor
     * 
     */
    ~Point() = default;
    //@}

    /**
     * @name Comparison operators
     */
    //@{
    /**
     * @brief Greater than operator.
     */
    bool operator>(const Point<T, N>& rhs) const;

    /**
     * @brief Greater than or equals operator.
     */
    bool operator>=(const Point<T, N>& rhs) const;

    /**
     * @brief Equals operator.
     */
    bool operator==(const Point<T, N>& rhs) const;

    /**
     * @brief Not equals operator.
     */
    bool operator!=(const Point<T, N>& rhs) const;

    /**
     * @brief Smaller than operator.
     */
    bool operator<(const Point<T, N>& rhs) const;

    /**
     * @brief Smaller than or equals operator.
     */
    bool operator<=(const Point<T, N>& rhs) const;
    //@}

    /**
     * @name Scalar arithmetic operations
     */
    //@{
    /**
     * @brief Addition operator.
     */
    Point<T, N> operator+(const T& scalar) const;

    /**
     * @brief Addition assignment operator.
     */
    Point<T, N>& operator+=(const T& scalar);

    /**
     * @brief Subtraction operator.
     */
    Point<T, N> operator-(const T& scalar) const;

    /**
     * @brief Subtraction assignment operator.
     */
    Point<T, N>& operator-=(const T& scalar);

    /**
     * @brief Multiplication operator.
     */
    Point<T, N> operator*(const T& scalar) const;

    /**
     * @brief Multiplication assignment operator.
     */
    Point<T, N>& operator*=(const T& scalar);

    /**
     * @brief Division operator.
     */
    Point<T, N> operator/(const T& scalar) const;

    /**
     * @brief Division assignment operator.
     */
    Point<T, N>& operator/=(const T& scalar);
    //@}

    /**
     * @name Point arithmetic operations
     */
    //@{
    /**
     * @brief Addition operator.
     */
    Point<T, N> operator+(const Point<T, N>& rhs) const;

    /**
     * @brief Addition assignment operator.
     */
    Point<T, N>& operator+=(const Point<T, N>& rhs);

    /**
     * @brief Subtraction operator.
     */
    Point<T, N> operator-(const Point<T, N>& rhs) const;

    /**
     * @brief Subtraction assigment operator.
     */
    Point<T, N>& operator-=(const Point<T, N>& rhs);

    /**
     * @brief Multiplication operator.
     */
    Point<T, N> operator*(const Point<T, N>& rhs) const;

    /**
     * @brief Multiplication assignment operator.
     */
    Point<T, N>& operator*=(const Point<T, N>& rhs);

    /**
     * @brief Division operator.
     */
    Point<T, N> operator/(const Point<T, N>& rhs) const;

    /**
     * @brief Division assignment operator.
     */
    Point<T, N>& operator/=(const Point<T, N>& rhs);

    /**
     * @brief Assignment operator.
     */
    Point<T, N>& operator=(const Point<T, N>& rhs);

    /**
     * @brief Move assignment operator.
     */
    Point<T, N>& operator=(Point<T, N>&& rhs);
    //@}

    /**
     * @name Element access
     */
    //@{
    /**
     * @brief Returns a non-const reference to the coordinate at the given index.
     * Be careful because with this operator the coordinates can be get and set.
     * Note that this function only checks in debug mode if the index is not out of bound.
     * @param index The index: 0 = x, 1 = y, 2 = z (only in 3D)
     * @return T& The coordinate.
     */
    T& operator[](std::size_t index);

    const T& operator[](std::size_t index) const;

    /**
     * @brief Gets a const reference to the coordinate at the given index.
     * This is a safer alternative to the operator[].
     * Note that this function only checks in debug mode if the index is not out of bound.
     * @param index The index: 0 = x, 1 = y, 2 = z (only in 3D)
     * @return const T& The coordinate.
     */
    const T& get(std::size_t index) const;

    /**
     * @brief Sets the coordinate at the given index to the given value.
     * Note that this function only checks in debug mode if the index is not out of bound.
     * @param index The index: 0 = x, 1 = y, 2 = z (only in 3D) 
     * @param value The value.
     */
    void set(std::size_t index, const T& value);

    /**
     * @brief Gets a const reference to the x coordinate.
     * 
     * @return const T& The x coordinate.
     */
    const T& x() const;

    /**
     * @brief Gets a const reference to the y coordinate.
     * 
     * @return const T& The y coordinate.
     */
    const T& y() const;

    /**
     * @brief Gets a const reference to the z coordinate. Only works in 3D.
     * 
     * @return const T& The z coordinate.
     */
    const T& z() const;
    //@}

    /**
     * @name Point functions
     */
    //@{
    
    /**
     * @brief Calculates the dot product of this point and another point.
     * 
     * @param rhs The other point.
     * @return const T The dot product.
     */
    const T dotProduct(const Point<T, N>& rhs) const;

    /**
     * @brief Calculates the magnitude of this point.
     * 
     * @return const T The magnitude.
     */
    const T magnitude() const;

    /**
     * @brief Calculates the cosine similarity between this point and another point.
     * 
     * @param rhs The other point.
     * @return const T The cosine similarity.
     */
    const T cosineSim(const Point<T, N>& rhs) const;
    //@}

  private:
    std::array<T, N> data;
  };

  template <typename T, std::size_t N> inline std::ostream &operator<<(std::ostream &os, const Point<T, N>& rhs)
  {
    os << "(";
    for(std::size_t i = 0; i < N; ++i)
    {
      os << rhs.get(i);
      if(i != N -1) os << ", ";
    }
    os << ")";
    return os;
  }

  template <typename T>
  using Point2D = Point<T, 2>;

  using Point2Ds = Point2D<std::size_t>;

  template <typename T>
  using Point3D = Point<T, 3>;

  using Point3Ds = Point3D<std::size_t>;
}
#include "Point.ipp"

#endif// POINT_HPP