#include "pig_latin.h"

namespace pig_latin {

// TODO: add your solution here
std::string translate(std::string text) {
    if (text.empty()) {
        return "";
    }
    std::string translation;
    while(!text.empty()) {
        if (text.find(' ') != std::string::npos) {
            translation += _translate_word(text.substr(0, text.find(' '))) + ' '; 
            if (text.find(' ') + 1 < text.length()) {
                text = text.substr(text.find(' ') + 1, std::string::npos);
            } else {
                text.clear();
            }
        } else {
            translation += _translate_word(text);
            break;
        }
    }
    return translation;
}

std::string _translate_word(std::string word) {
    size_t count{0};
    size_t length{word.length()};
    std::string vowels{"aeiou"};
    std::string sub_txt;
    for (size_t i{0}; i < length - 1; ++i) {
        if (word.substr(0,2) == "yt" || 
            word.substr(0,2) == "xr") {
            break;
        }
        char c{word.at(i)};
        if (vowels.find(c) != std::string::npos ||
            (i != 0 && c == 'y')) {
            break;
        }
        if (c == 'q' && word.at(i + 1) == 'u') {
            word += "qu";
            count += 2;
            ++i;
            continue;
        }
        word.push_back(c);
        ++count;
    }
    for (size_t i{0}; i < count; ++i) {
        word.erase(word.begin());
    }
    word += "ay";
    return word;
}

}  // namespace pig_latin
