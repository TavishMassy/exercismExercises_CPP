#include "hamming.h"

namespace hamming {

// TODO: add your solution here
int compute(std::string original, std::string copy) {
    int differences{0};
    size_t length{original.length()};
    if (length != copy.length()) throw std::domain_error("");
    for (size_t i{0}; i < length; ++i) {
        if (original.at(i) != copy.at(i)) {
            ++differences;
        }
    }
    return differences;
}

}  // namespace hamming
