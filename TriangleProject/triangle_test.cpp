#include <gtest/gtest.h>
#include "triangle.h"

TEST(TriangleTest, EquilateralTriangle) {
    Triangle t;
    EXPECT_TRUE(t.isValid(5, 5, 5));
    EXPECT_EQ(t.getType(5, 5, 5), "Equilateral");
}

TEST(TriangleTest, IsoscelesTriangle) {
    Triangle t;
    EXPECT_TRUE(t.isValid(5, 5, 3));
    EXPECT_EQ(t.getType(5, 5, 3), "Isosceles");
}

TEST(TriangleTest, IsoscelesAnyPairOfSides) {
    Triangle t;
    EXPECT_EQ(t.getType(3, 5, 5), "Isosceles"); // b == c
    EXPECT_EQ(t.getType(5, 3, 5), "Isosceles"); // a == c
}

TEST(TriangleTest, ScaleneTriangle) {
    Triangle t;
    EXPECT_TRUE(t.isValid(4, 5, 6));
    EXPECT_EQ(t.getType(4, 5, 6), "Scalene");
}

TEST(TriangleTest, DifferentOrder) {
    Triangle t;
    EXPECT_TRUE(t.isValid(3, 5, 4));
    EXPECT_EQ(t.getType(3, 5, 4), "Scalene");
}

TEST(TriangleTest, InvalidTriangle) {
    Triangle t;
    EXPECT_FALSE(t.isValid(1, 2, 3));
    EXPECT_EQ(t.getType(1, 2, 3), "Invalid");
}

TEST(TriangleTest, InvalidTriangleOneLongSide) {
    Triangle t;
    EXPECT_FALSE(t.isValid(1, 1, 5));
    EXPECT_EQ(t.getType(1, 1, 5), "Invalid");
}

TEST(TriangleTest, ZeroSide) {
    Triangle t;
    EXPECT_FALSE(t.isValid(0, 4, 4));
    EXPECT_EQ(t.getType(0, 4, 4), "Invalid");
}

TEST(TriangleTest, NegativeSide) {
    Triangle t;
    EXPECT_FALSE(t.isValid(-2, 4, 5));
    EXPECT_EQ(t.getType(-2, 4, 5), "Invalid");
}

TEST(TriangleTest, EqualBoundaryCase) {
    Triangle t;
    EXPECT_FALSE(t.isValid(2, 2, 4));
    EXPECT_EQ(t.getType(2, 2, 4), "Invalid");
}

TEST(TriangleTest, JustAboveBoundary) {
    Triangle t;
    EXPECT_TRUE(t.isValid(2, 3, 4));
    EXPECT_EQ(t.getType(2, 3, 4), "Scalene");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
