#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

// Triangle: validates three side lengths and classifies the triangle.
// getType() returns "Equilateral", "Isosceles", "Scalene" or "Invalid".
class Triangle {
public:
    bool isValid(int a, int b, int c);
    std::string getType(int a, int b, int c);
};

#endif
