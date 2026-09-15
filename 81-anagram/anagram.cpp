#include "anagram.h"

namespace anagram {

// TODO: add your solution here
anagram::anagram(std::string word) {
    for (char c : word) {
        if (isalpha(c)) {
            c = tolower(c);
            _word.push_back(c);
            if (_word_map.find(c) != _word_map.end()) {
                ++_word_map[c];
            } else {
                _word_map[c] = 1;
                _word_char.push_back(c);
            }
        }
    }
}

std::unordered_set<std::string> anagram::matches(std::unordered_set<std::string> words) {
    std::unordered_set<std::string> words_found;
    std::unordered_map<char, size_t> word_map;
    std::string current_word;
    bool no_match{false};
    for (std::string word : words) { 
        current_word.clear();
        word_map.clear();
        no_match = false;
        for (char c : word) {
            c = tolower(c);
            current_word.push_back(c);
            if (word_map.find(c) != word_map.end()) {
                ++word_map[c];
            } else {
                word_map[c] = 1;
            }
        }
        if (current_word == _word) {
            continue;
        }
        for (char c : _word_char) {
            if (word_map.find(c) == word_map.end()) {
                no_match = true;
                break;
            }
            if (word_map.at(c) != _word_map.at(c)) {
                no_match = true;
                break;
            }
            word_map.erase(c);
        }
        if (!word_map.empty()) {
            continue;
        }
        if (!no_match) {
            words_found.insert(word);
        }
    } 
    return words_found;
}

}  // namespace anagram
