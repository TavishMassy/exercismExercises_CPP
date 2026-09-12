#pragma once
#include <string>
#include <vector>

namespace roman_numerals {

const std::vector<std::pair<std::string, int>> roman_vals{
    {"M", 1000}, {"CM", 900},
    {"D", 500}, {"CD", 400},
    {"C", 100}, {"XC", 90},
    {"L", 50}, {"XL", 40},
    {"X", 10}, {"IX", 9},
    {"V", 5}, {"IV", 4},
    {"I", 1}
};

std::string convert(int num);

}  // namespace roman_numerals
