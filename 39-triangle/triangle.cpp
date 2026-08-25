#include "triangle.h"

namespace triangle {

// TODO: add your solution here
flavor kind(double a, double b, double c) {
    if (a + b <= c || b + c <= a || a + c <= b ||
        a <= 0 || b <= 0 || c <= 0) {
        throw std::domain_error("Sides do not form a valid triangle.");
    }
    if (a == b && b == c) {
        return flavor::equilateral;
    } else if (a == b || b == c || a == c) {
        return flavor::isosceles;
    }
    return flavor::scalene;
}

}  // namespace triangle
