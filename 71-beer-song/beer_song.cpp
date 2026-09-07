#include "beer_song.h"
#include <iostream>

namespace beer_song {

// TODO: add your solution here
std::string verse(int num) {
    std::string current = _bottles(num) + " of beer";
    std::string next = _bottles(num == 0 ? 99 : num - 1) + " of beer";
    
    std::string action = (num == 0) ? "Go to the store and buy some more, " 
                       : (num == 1) ? "Take it down and pass it around, " 
                       : "Take one down and pass it around, ";

    return _Capitalize(current) + " on the wall, " + current + ".\n" +
           action + next + " on the wall.\n";
}

std::string _bottles(int n) {
    if (n == 0) return "no more bottles";
    if (n == 1) return "1 bottle";
    return std::to_string(n) + " bottles";
}

std::string _Capitalize(std::string s) {
    if (!s.empty()) s[0] = std::toupper(s[0]);
    return s;
}

std::string sing(int start, int stop) {
    std:: string lyrics;
    for (int i{start}; i > stop; --i) {
        lyrics += verse(i) + "\n";
    }
    lyrics += verse(stop);
    return lyrics;
}

}  // namespace beer_song
