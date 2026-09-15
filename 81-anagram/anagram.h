#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace anagram {

// TODO: add your solution here
class anagram {
private:
    std::unordered_map<char, size_t> _word_map;
    std::string _word_char;   
    std::string _word;

public:
    anagram(std::string word);
    std::unordered_set<std::string> matches(std::unordered_set<std::string> words);
};

}  // namespace anagram
