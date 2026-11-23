#include "triangle.h"

bool Triangle::isValid(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return false;
    }
    long long x = a, y = b, z = c;
   return (x + y > z) && (x + z > y) && (y + z > x);
}

std::string Triangle::getType(int a, int b, int c) {
    if (!isValid(a, b, c)) {
        return "Invalid";
    }
    if (a == b && b == c) {
        return "Equilateral";
    }
    if (a == b || b == c || a == c) {
        return "Isosceles";
    }
    return "Scalene";
}
