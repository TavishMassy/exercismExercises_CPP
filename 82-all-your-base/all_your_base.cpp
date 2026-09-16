#include "all_your_base.h"
#include <iostream>

namespace all_your_base {

// TODO: add your solution here
std::vector<unsigned int> convert(unsigned int from_base, std::vector<unsigned int> digits, unsigned int to_base) {
    if (from_base == to_base) {
        return digits;
    }
    if (from_base < 2 || to_base < 2) {
        throw std::invalid_argument("ERROR: Invalid base conversion (base less than 2).");
    }
    if (digits.empty()) {
        return {};
    
    }
    unsigned int num{0};
    if (from_base != 10) {    
        unsigned int exp{static_cast<unsigned int>(digits.size()) - 1};
        unsigned int exp_value;
        for (unsigned int i{0}; i < static_cast<unsigned int>(digits.size()); ++i) {
            if (digits.at(i) >= from_base) {
                throw std::invalid_argument("ERROR: Invalid digit(s) provided (more than or equal to its base).");
            }
            exp_value = 1;
            for (unsigned int _{0}; _ < exp; ++_) {
                exp_value *= from_base;
            }
            num += digits.at(i) * exp_value;
            --exp;
        }
    } else {
        for (unsigned int i : digits) {
            num *= 10;
            num += i;
        }
    }

    std::vector<unsigned int> to_base_digits;
    if (num == 0) {
        return {};
    } else {
        unsigned int remainder;
        while (num > 0) {
            remainder = num % to_base;
            to_base_digits.insert(to_base_digits.begin(), remainder);
            num -= remainder;
            num /= to_base;
        }
    }
    return to_base_digits;
}

}  // namespace all_your_base
