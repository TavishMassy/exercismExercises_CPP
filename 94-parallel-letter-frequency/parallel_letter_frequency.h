#pragma once
#include <unordered_map>
#include <string_view>
#include <vector>

namespace parallel_letter_frequency {

std::unordered_map<char, size_t> frequency(std::vector<std::string_view> const& text);

}
