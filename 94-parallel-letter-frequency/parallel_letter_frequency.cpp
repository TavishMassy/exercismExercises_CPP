#include "parallel_letter_frequency.h"

namespace parallel_letter_frequency {

std::unordered_map<char, size_t> frequency(std::vector<std::string_view> const& text) {
    std::unordered_map<char, size_t> letter_map;
    for (std::string_view stanza : text) {
        for (char c : stanza) {
            if (iswalpha(c)) {
                c = towlower(c);
                if (letter_map.find(c) == letter_map.end()) {
                    letter_map[c] = 1;
                } else {
                    ++letter_map[c];
                }
            }
        }
    }
    return letter_map;
}
    
}
