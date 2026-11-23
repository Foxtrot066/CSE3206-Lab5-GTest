#include <gtest/gtest.h>
#include <stdexcept>
#include "student_grade.h"

TEST(StudentGradeTest, TotalMarks) {
    StudentGrade student;
    EXPECT_EQ(student.total(80, 70, 90), 240);
    EXPECT_EQ(student.total(55, 65, 75), 195);
}

TEST(StudentGradeTest, AllMarksZero) {
    StudentGrade student;
    EXPECT_EQ(student.total(0, 0, 0), 0);
    EXPECT_DOUBLE_EQ(student.average(0, 0, 0), 0.0);
    EXPECT_EQ(student.grade(student.average(0, 0, 0)), 'F');
}

TEST(StudentGradeTest, FullMarks) {
    StudentGrade student;
    EXPECT_EQ(student.total(100, 100, 100), 300);
    EXPECT_DOUBLE_EQ(student.average(100, 100, 100), 100.0);
    EXPECT_EQ(student.grade(100.0), 'A');
}

TEST(StudentGradeTest, AverageMarks) {
    StudentGrade student;
    EXPECT_DOUBLE_EQ(student.average(80, 70, 90), 80.0);
    EXPECT_DOUBLE_EQ(student.average(50, 60, 70), 60.0);
    EXPECT_NEAR(student.average(80, 85, 85), 83.3333, 0.001);
}

TEST(StudentGradeTest, GradeCalculation) {
    StudentGrade student;
    EXPECT_EQ(student.grade(90.0), 'A');
    EXPECT_EQ(student.grade(75.0), 'B');
    EXPECT_EQ(student.grade(65.0), 'C');
    EXPECT_EQ(student.grade(55.0), 'D');
    EXPECT_EQ(student.grade(30.0), 'F');
}

TEST(StudentGradeTest, BoundaryValues) {
    StudentGrade student;
    EXPECT_EQ(student.grade(80.0), 'A');
    EXPECT_EQ(student.grade(79.99), 'B');
    EXPECT_EQ(student.grade(70.0), 'B');
    EXPECT_EQ(student.grade(69.99), 'C');
    EXPECT_EQ(student.grade(60.0), 'C');
    EXPECT_EQ(student.grade(59.99), 'D');
    EXPECT_EQ(student.grade(50.0), 'D');
    EXPECT_EQ(student.grade(49.99), 'F');
    EXPECT_EQ(student.grade(0.0), 'F');
}

TEST(StudentGradeTest, InvalidMarks) {
    StudentGrade student;
    EXPECT_THROW(student.total(-1, 50, 50), std::invalid_argument);
    EXPECT_THROW(student.total(50, 101, 50), std::invalid_argument);
    EXPECT_THROW(student.average(50, 50, -10), std::invalid_argument);
    EXPECT_THROW(student.grade(-5.0), std::invalid_argument);
    EXPECT_THROW(student.grade(100.5), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
