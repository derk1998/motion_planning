#include <gtest/gtest.h>
#include <Box.hpp>

TEST(BoxSuite, defaultConstructor2D)
{
    Base::Box2Ds box;
    ASSERT_EQ(box[0], Base::Point2Ds(0,0));
    ASSERT_EQ(box[1], Base::Point2Ds(0,0));
}

TEST(BoxSuite, defaultConstructor3D)
{
    Base::Box3Ds box;
    ASSERT_EQ(box[0], Base::Point3Ds(0,0,0));
    ASSERT_EQ(box[1], Base::Point3Ds(0,0,0));
}

TEST(BoxSuite, pointConstructor2D)
{
    Base::Point2Ds p1(10,20);
    Base::Point2Ds p2(400,100);
    Base::Box2Ds box(p1,p2);
    ASSERT_EQ(box[0], p1);
    ASSERT_EQ(box[1], p2);
}

TEST(BoxSuite, pointConstructor3D)
{
    Base::Point3Ds p1(10,20,20);
    Base::Point3Ds p2(400,100,500);
    Base::Box3Ds box(p1,p2);
    ASSERT_EQ(box[0], p1);
    ASSERT_EQ(box[1], p2);
}

TEST(BoxSuite, copyConstructor2D)
{
    Base::Point2Ds p1(10,20);
    Base::Point2Ds p2(400,100);
    Base::Box2Ds box(p1, p2);

    Base::Box2Ds box2(box);

    ASSERT_EQ(box[0], box2[0]);
    ASSERT_EQ(box[1], box2[1]);
}

TEST(BoxSuite, copyConstructor3D)
{
    Base::Point3Ds p1(10,20,20);
    Base::Point3Ds p2(400,100,500);
    Base::Box3Ds box(p1,p2);

    Base::Box3Ds box2(box);

    ASSERT_EQ(box[0], box2[0]);
    ASSERT_EQ(box[1], box2[1]);
}

TEST(BoxSuite, moveConstructor2D)
{

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}