#pragma once
#include <string>
#include <vector>

namespace resistor_color_duo {

// TODO: add your solution here
const std::vector<std::string> color_names{
    "black",  "brown", "red",  "orange",
    "yellow", "green", "blue", "violet",
    "grey",   "white"
};

const std::vector<int> color_codes{
    0, 1, 2, 3,
    4, 5, 6, 7,
    8, 9
};

int color_code(std::string);
int value(std::vector<std::string>);

}  // namespace resistor_color_duo
