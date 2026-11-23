#include "student_grade.h"
#include <stdexcept>

void StudentGrade::validateMark(int mark) {
    if (mark < 0 || mark > 100) {
        throw std::invalid_argument("Mark must be between 0 and 100");
    }
}

int StudentGrade::total(int a, int b, int c) {
    validateMark(a);
    validateMark(b);
    validateMark(c);
    return a + b + c;
}

double StudentGrade::average(int a, int b, int c) {
    return total(a, b, c) / 3.0; // 3.0 forces floating-point division
}

char StudentGrade::grade(double average) {
    if (average < 0.0 || average > 100.0) {
        throw std::invalid_argument("Average must be between 0 and 100");
    }
    if (average >= 80.0) return 'A';
    if (average >= 70.0) return 'B';
    if (average >= 60.0) return 'C';
    if (average >= 50.0) return 'D';
    return 'F';
}
