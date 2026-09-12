#include "roman_numerals.h"

namespace roman_numerals {

std::string convert(int num) {
    std::string roman_num;
    for (std::pair<std::string, int> roman : roman_vals) {
        while (roman.second <= num) {
            roman_num += roman.first;
            num -= roman.second;
        }
    }
    return roman_num;
}

}  // namespace roman_numerals
