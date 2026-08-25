#pragma once
#include <stdexcept>

namespace triangle {

// TODO: add your solution here
enum flavor{
    equilateral,
    isosceles,
    scalene
};

flavor kind(double a, double b, double c);

}  // namespace triangle
