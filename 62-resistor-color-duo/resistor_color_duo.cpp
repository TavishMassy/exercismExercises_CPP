#include "resistor_color_duo.h"

namespace resistor_color_duo {

// TODO: add your solution here
int color_code(std::string color) {
    for (size_t i{0}; i < color_names.size(); ++i) {
        if (color == color_names.at(i)) {
            return color_codes.at(i);
        }
    }
    return 0;
}

int value(std::vector<std::string> colors) {
    int value{0};
    for (size_t i{0}; i < 2; ++i) {
        value *= 10;
        value += color_code(colors.at(i));
    }
    return value;
}

}  // namespace resistor_color_duo
