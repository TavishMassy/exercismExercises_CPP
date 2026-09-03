#include "resistor_color.h"

namespace resistor_color {

// TODO: add your solution here
int color_code(std::string color) {
    for (size_t i{0}; i < color_names.size(); ++i) {
        if (color == color_names.at(i)) {
            return color_codes.at(i);
        }
    }
    return 0;
}

std::vector<std::string> colors() {
    return  color_names;
}

}  // namespace resistor_color
