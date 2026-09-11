#pragma once
#include <string>
#include <vector>

namespace food_chain {

// TODO: add your solution here
std::string verse(size_t index);
std::string verses(size_t index_1, size_t index_2);
inline std::string sing() { return verses(1, 8); }

}  // namespace food_chain
