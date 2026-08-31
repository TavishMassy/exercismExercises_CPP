#include "etl.h"

namespace etl {

// TODO: add your solution here
std::map<char, int> transform(std::map<int, std::vector<char>> int_char_arr_map) {
    std::map<char, int> char_int_map{};
    for (auto [num, str_arr] : int_char_arr_map) {
        for (char c : str_arr) {
            c = tolower(c);
            char_int_map[c] = num;
        }
    }
    return char_int_map;
}

}  // namespace etl
