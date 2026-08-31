#include "binary.h"

namespace binary {

// TODO: add your solution here
int convert(std::string binary_txt)  {
    int binary_int{0};
    int length{static_cast<int>(binary_txt.length())};
    if (length == 0) return 0;
    int j{1};
    for (int i{length - 1}; i >= 0; --i) {
        char &c{binary_txt.at(i)};
        if (c != '0' && c != '1') return 0;
        if (c == '1') {
            binary_int += j;
        }
        j *= 2;
    }
    return binary_int;
}

}  // namespace binary
