#include "word_count.h"
#include <iostream>

namespace word_count {

// TODO: add your solution here
std::map<std::string, int> words(std::string text) {
    std::map<std::string, int> word_map;
    std::string word;
    for (char c : text) {
        c = tolower(c);
        if (isspace(c) || c == ',') {
            _find_word_add_count(word, word_map);
        } else if (isalnum(c) || c == '\'') {
            if(word.empty() && c == '\'') {
                continue;
            }
            word.push_back(c);
        }
    }
    _find_word_add_count(word, word_map);
    return word_map;
}

void _find_word_add_count(std::string& word, std::map<std::string, int>& word_map) {
    if (word.empty()) {
        return;
    }
    if (word.at(0) == '\'') {
        word.erase(0);
    }
    if (word.back() == '\'') {
        word.pop_back();
    }
    std::cout << word << std::endl;
    if (word_map.find(word) != word_map.end()) {
        ++word_map[word];
        word.clear();
    } else {
        word_map[word] = 1;
        word.clear();
    }
    
}

}  // namespace word_count
