#pragma once
#include <string>
#include <vector>
#include <stdexcept>

namespace say {

// TODO: add your solution here
const std::vector<std::string> ones = {
    "zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ",
    "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ",
    "seventeen ", "eighteen ", "nineteen "
};

const std::vector<std::string> tens = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

std::string in_english(long long num);

}  // namespace say
