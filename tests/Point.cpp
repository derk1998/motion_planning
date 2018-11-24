#include <gtest/gtest.h>
#include <Point.hpp>

TEST(PointSuite, lessThanOperator2D)
{
    Base::Point<unsigned short, 2> p0;
    Base::Point<unsigned short, 2> p1(4, 1);
    Base::Point<unsigned short, 2> p2(10, 20);
    Base::Point<unsigned short, 2> p3(4, 2);

    ASSERT_EQ(p1 < p2, true);
    ASSERT_EQ(p3 < p1, false);
    ASSERT_EQ(p1 < p1, false);
}

TEST(PointSuite, lessThanOperator3D)
{
    Base::Point<unsigned short, 3> p1(4, 1, 1);
    Base::Point<unsigned short, 3> p2(10, 20, 10);
    Base::Point<unsigned short, 3> p3(4, 2, 5);

    ASSERT_EQ(p1 < p2, true);
    ASSERT_EQ(p3 < p1, false);
    ASSERT_EQ(p1 < p1, false);
}

TEST(PointSuite, equalsOperator2D)
{
    Base::Point<unsigned short, 2> p1(4, 1);
    Base::Point<unsigned short, 2> p2(10, 20);
    Base::Point<unsigned short, 2> p3(4, 1);

    ASSERT_EQ(p1 == p2, false);
    ASSERT_EQ(p1 == p1, true);
    ASSERT_EQ(p1 == p3, true);
}

TEST(PointSuite, equalsOperator3D)
{
    Base::Point<unsigned short, 3> p1(4, 1, 2);
    Base::Point<unsigned short, 3> p2(10, 20, 1);
    Base::Point<unsigned short, 3> p3(4, 1, 2);

    ASSERT_EQ(p1 == p2, false);
    ASSERT_EQ(p1 == p1, true);
    ASSERT_EQ(p1 == p3, true);
}

TEST(PointSuite, equalsOperatorFloat)
{
    float d2 = 1 / std::sqrt(5) / std::sqrt(5);
    Base::Point<float, 3> p1(0.2, 0.2, 0.2);
    Base::Point<float, 3> p2(d2, d2, d2);

    ASSERT_EQ(p1 == p2, true);
}

TEST(PointSuite, notEqualsOperator2D)
{
    Base::Point<unsigned short, 2> p1(4, 1);
    Base::Point<unsigned short, 2> p2(10, 20);
    Base::Point<unsigned short, 2> p3(4, 1);

    ASSERT_EQ(p1 != p2, true);
    ASSERT_EQ(p1 != p1, false);
    ASSERT_EQ(p1 != p3, false);
}

TEST(PointSuite, notEqualsOperator3D)
{
    Base::Point<unsigned short, 3> p1(4, 1, 2);
    Base::Point<unsigned short, 3> p2(10, 20, 1);
    Base::Point<unsigned short, 3> p3(4, 1, 2);

    ASSERT_EQ(p1 != p2, true);
    ASSERT_EQ(p1 != p1, false);
    ASSERT_EQ(p1 != p3, false);
}

TEST(PointSuite, lessThanOrEqualsOperator2D)
{
    Base::Point<unsigned short, 2> p1(4, 1);
    Base::Point<unsigned short, 2> p2(10, 20);
    Base::Point<unsigned short, 2> p3(4, 2);
    Base::Point<unsigned short, 2> p4(4, 1);

    ASSERT_EQ(p1 <= p2, true);
    ASSERT_EQ(p3 <= p1, false);
    ASSERT_EQ(p1 <= p1, true);
    ASSERT_EQ(p1 <= p4, true);
}

TEST(PointSuite, lessThanOrEqualsOperator3D)
{
    Base::Point<unsigned short, 3> p1(4, 1, 1);
    Base::Point<unsigned short, 3> p2(10, 20, 10);
    Base::Point<unsigned short, 3> p3(4, 2, 5);
    Base::Point<unsigned short, 3> p4(4, 1, 1);

    ASSERT_EQ(p1 <= p2, true);
    ASSERT_EQ(p3 <= p1, false);
    ASSERT_EQ(p1 <= p1, true);
    ASSERT_EQ(p1 <= p4, true);
}

TEST(PointSuite, greaterThanOperator2D)
{
    Base::Point<unsigned short, 2> p1(4, 1);
    Base::Point<unsigned short, 2> p2(10, 20);
    Base::Point<unsigned short, 2> p3(4, 2);

    ASSERT_EQ(p1 > p2, false);
    ASSERT_EQ(p3 > p1, true);
    ASSERT_EQ(p1 > p1, false);
}

TEST(PointSuite, greaterThanOperator3D)
{
    Base::Point<unsigned short, 3> p1(4, 1, 1);
    Base::Point<unsigned short, 3> p2(10, 20, 10);
    Base::Point<unsigned short, 3> p3(4, 2, 5);

    ASSERT_EQ(p1 > p2, false);
    ASSERT_EQ(p3 > p1, true);
    ASSERT_EQ(p1 > p1, false);
}

TEST(PointSuite, greaterThanOrEqualsOperator2D)
{
    Base::Point<unsigned short, 2> p1(4, 1);
    Base::Point<unsigned short, 2> p2(10, 20);
    Base::Point<unsigned short, 2> p3(4, 2);
    Base::Point<unsigned short, 2> p4(4, 1);

    ASSERT_EQ(p1 >= p2, false);
    ASSERT_EQ(p3 >= p1, true);
    ASSERT_EQ(p1 >= p1, true);
    ASSERT_EQ(p1 >= p4, true);
}

TEST(PointSuite, greaterThanOrEqualsOperator3D)
{
    Base::Point<unsigned short, 3> p1(4, 1, 1);
    Base::Point<unsigned short, 3> p2(10, 20, 10);
    Base::Point<unsigned short, 3> p3(4, 2, 5);
    Base::Point<unsigned short, 3> p4(4, 1, 1);

    ASSERT_EQ(p1 >= p2, false);
    ASSERT_EQ(p3 >= p1, true);
    ASSERT_EQ(p1 >= p1, true);
    ASSERT_EQ(p1 >= p4, true);
}

TEST(PointSuite, additionOperator2DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short xTotal = x1 + x2;
    unsigned short yTotal = y1 + y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    ASSERT_EQ(p1 + p2, p3);
}

TEST(PointSuite, additionOperator2DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 + scalar;
    unsigned short yTotal = y1 + scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    ASSERT_EQ(p1 + scalar, p2);
}

TEST(PointSuite, subtractionOperator2DPoint)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short x2 = 4;
    unsigned short y2 = 5;

    unsigned short xTotal = x1 - x2;
    unsigned short yTotal = y1 - y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    ASSERT_EQ(p1 - p2, p3);
}

TEST(PointSuite, subtractionOperator2DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 - scalar;
    unsigned short yTotal = y1 - scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    ASSERT_EQ(p1 - scalar, p2);
}

TEST(PointSuite, additionAssignmentOperator2DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short xTotal = x1 + x2;
    unsigned short yTotal = y1 + y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    p1 += p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, additionAssignmentOperator2DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 + scalar;
    unsigned short yTotal = y1 + scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    p1 += scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, subtractionAssignmentOperator2DPoint)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short x2 = 4;
    unsigned short y2 = 5;

    unsigned short xTotal = x1 - x2;
    unsigned short yTotal = y1 - y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    p1 -= p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, subtractionAssignmentOperator2DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short scalar = 5;

    unsigned short xTotal = x1 - scalar;
    unsigned short yTotal = y1 - scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    p1 -= scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, additionOperator3DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short xTotal = x1 + x2;
    unsigned short yTotal = y1 + y2;
    unsigned short zTotal = z1 + z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 + p2, p3);
}

TEST(PointSuite, additionOperator3DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 + scalar;
    unsigned short yTotal = y1 + scalar;
    unsigned short zTotal = z1 + scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 + scalar, p2);
}

TEST(PointSuite, subtractionOperator3DPoint)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short z1 = 30;
    unsigned short x2 = 4;
    unsigned short y2 = 10;
    unsigned short z2 = 5;

    unsigned short xTotal = x1 - x2;
    unsigned short yTotal = y1 - y2;
    unsigned short zTotal = z1 - z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 - p2, p3);
}

TEST(PointSuite, subtractionOperator3DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short z1 = 30;
    unsigned short scalar = 5;

    unsigned short xTotal = x1 - scalar;
    unsigned short yTotal = y1 - scalar;
    unsigned short zTotal = z1 - scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 - scalar, p2);
}

TEST(PointSuite, additionAssignmentOperator3DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short xTotal = x1 + x2;
    unsigned short yTotal = y1 + y2;
    unsigned short zTotal = z1 + z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    p1 += p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, additionAssignmentOperator3DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 + scalar;
    unsigned short yTotal = y1 + scalar;
    unsigned short zTotal = z1 + scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    p1 += scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, subtractionAssignmentOperator3DPoint)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short z1 = 30;
    unsigned short x2 = 5;
    unsigned short y2 = 10;
    unsigned short z2 = 2;

    unsigned short xTotal = x1 - x2;
    unsigned short yTotal = y1 - y2;
    unsigned short zTotal = z1 - z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    p1 -= p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, subtractionAssignmentOperator3DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short z1 = 30;
    unsigned short scalar = 5;

    unsigned short xTotal = x1 - scalar;
    unsigned short yTotal = y1 - scalar;
    unsigned short zTotal = z1 - scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    p1 -= scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, multiplicationOperator2DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short xTotal = x1 * x2;
    unsigned short yTotal = y1 * y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    ASSERT_EQ(p1 * p2, p3);
}

TEST(PointSuite, multiplicationOperator2DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 * scalar;
    unsigned short yTotal = y1 * scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    ASSERT_EQ(p1 * scalar, p2);
}

TEST(PointSuite, multiplicationOperator3DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short xTotal = x1 * x2;
    unsigned short yTotal = y1 * y2;
    unsigned short zTotal = z1 * z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 * p2, p3);
}

TEST(PointSuite, multiplicationOperator3DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 * scalar;
    unsigned short yTotal = y1 * scalar;
    unsigned short zTotal = z1 * scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 * scalar, p2);
}

TEST(PointSuite, divisionOperator2DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short xTotal = x1 / x2;
    unsigned short yTotal = y1 / y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    ASSERT_EQ(p1 / p2, p3);
}

TEST(PointSuite, divisionOperator2DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 / scalar;
    unsigned short yTotal = y1 / scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    ASSERT_EQ(p1 / scalar, p2);
}

TEST(PointSuite, divisionOperator3DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short xTotal = x1 / x2;
    unsigned short yTotal = y1 / y2;
    unsigned short zTotal = z1 / z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 / p2, p3);
}

TEST(PointSuite, divisionOperator3DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 / scalar;
    unsigned short yTotal = y1 / scalar;
    unsigned short zTotal = z1 / scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    ASSERT_EQ(p1 / scalar, p2);
}

TEST(PointSuite, multiplicationAssignmentOperator2DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short scalar = 5;

    unsigned short xTotal = x1 * scalar;
    unsigned short yTotal = y1 * scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    p1 *= scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, multiplicationAssignmentOperator2DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short xTotal = x1 * x2;
    unsigned short yTotal = y1 * y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    p1 *= p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, multiplicationAssignmentOperator3DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 * scalar;
    unsigned short yTotal = y1 * scalar;
    unsigned short zTotal = z1 * scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    p1 *= scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, multiplicationAssignmentOperator3DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short xTotal = x1 * x2;
    unsigned short yTotal = y1 * y2;
    unsigned short zTotal = z1 * z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    p1 *= p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, divisionAssignmentOperator2DScalar)
{
    unsigned short x1 = 10;
    unsigned short y1 = 20;
    unsigned short scalar = 5;

    unsigned short xTotal = x1 / scalar;
    unsigned short yTotal = y1 / scalar;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(xTotal, yTotal);

    p1 /= scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, divisionAssignmentOperator2DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short xTotal = x1 / x2;
    unsigned short yTotal = y1 / y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);
    Base::Point<unsigned short, 2> p3(xTotal, yTotal);

    p1 /= p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, divisionAssignmentOperator3DScalar)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short scalar = 10;

    unsigned short xTotal = x1 / scalar;
    unsigned short yTotal = y1 / scalar;
    unsigned short zTotal = z1 / scalar;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(xTotal, yTotal, zTotal);

    p1 /= scalar;

    ASSERT_EQ(p1, p2);
}

TEST(PointSuite, divisionAssignmentOperator3DPoint)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 5;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short xTotal = x1 / x2;
    unsigned short yTotal = y1 / y2;
    unsigned short zTotal = z1 / z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    Base::Point<unsigned short, 3> p3(xTotal, yTotal, zTotal);

    p1 /= p2;

    ASSERT_EQ(p1, p3);
}

TEST(PointSuite, dotProduct2D)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short result = x1 * x2 + y1 * y2;

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);

    ASSERT_EQ(p1.dotProduct(p2), result);
}

TEST(PointSuite, dotProduct3D)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 3;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short result = x1 * x2 + y1 * y2 + z1 * z2;

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);
    ASSERT_EQ(p1.dotProduct(p2), result);
}

TEST(PointSuite, magnitude2D)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;

    unsigned short result = std::sqrt(std::pow(x1, 2) + std::pow(y1, 2));
    Base::Point<unsigned short, 2> p1(x1, y1);

    ASSERT_EQ(p1.magnitude(), result);
}

TEST(PointSuite, magnitude3D)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 7;

    unsigned short result = std::sqrt(std::pow(x1, 2) + std::pow(y1, 2) + std::pow(z1, 2));
    Base::Point<unsigned short, 3> p1(x1, y1, z1);

    ASSERT_EQ(p1.magnitude(), result);
}

TEST(PointSuite, cosineSim2D)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short x2 = 10;
    unsigned short y2 = 20;

    unsigned short dotProduct = x1 * x2 + y1 * y2;
    unsigned short magnitudeP1 = std::sqrt(std::pow(x1, 2) + std::pow(y1, 2));
    unsigned short magnitudeP2 = std::sqrt(std::pow(x2, 2) + std::pow(y2, 2));
    unsigned short result = dotProduct / (magnitudeP1 * magnitudeP2);

    Base::Point<unsigned short, 2> p1(x1, y1);
    Base::Point<unsigned short, 2> p2(x2, y2);

    ASSERT_EQ(p1.cosineSim(p2), result);
}

TEST(PointSuite, cosineSim3D)
{
    unsigned short x1 = 4;
    unsigned short y1 = 1;
    unsigned short z1 = 10;
    unsigned short x2 = 10;
    unsigned short y2 = 20;
    unsigned short z2 = 10;

    unsigned short dotProduct = x1 * x2 + y1 * y2 + z1 * z2;
    unsigned short magnitudeP1 = std::sqrt(std::pow(x1, 2) + std::pow(y1, 2) + std::pow(z1, 2));
    unsigned short magnitudeP2 = std::sqrt(std::pow(x2, 2) + std::pow(y2, 2) + std::pow(z2, 2));
    unsigned short result = dotProduct / (magnitudeP1 * magnitudeP2);

    Base::Point<unsigned short, 3> p1(x1, y1, z1);
    Base::Point<unsigned short, 3> p2(x2, y2, z2);

    ASSERT_EQ(p1.cosineSim(p2), result);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}