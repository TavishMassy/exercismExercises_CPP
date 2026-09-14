#pragma once
#include <map>
#include <string>

namespace word_count {

// TODO: add your solution here
std::map<std::string, int> words(std::string text);
void _find_word_add_count(std::string& word, std::map<std::string, int>& word_map);

}  // namespace word_count
