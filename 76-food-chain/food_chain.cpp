#include "food_chain.h"

namespace food_chain {

// TODO: add your solution here
std::string verse(size_t index) {
    std::string lyric{"I know an old lady who swallowed a "};
    std::vector<std::string> animals{"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
    std::vector<std::string> reason{
        "I don't know why she swallowed the fly. Perhaps she'll die.\n",
        "It wriggled and jiggled and tickled inside her.\n",
        "How absurd to swallow a bird!\n",
        "Imagine that, to swallow a cat!\n",
        "What a hog, to swallow a dog!\n",
        "Just opened her throat and swallowed a goat!\n",
        "I don't know how she swallowed a cow!\n",
        "She's dead, of course!\n"
    };
    for (size_t i{index}; i > 0; --i) {
        if (i == index) {
            lyric += animals.at(index - 1) + ".\n";
            lyric += reason.at(index - 1);
        } else {
            lyric += "She swallowed the " + animals.at(i);
            lyric += " to catch the " + animals.at(i - 1)  + ".\n";
            if (i - 1 == 0) {
                lyric += reason.at(0);
            } else if (animals.at(i - 1) == "spider") {
                lyric.erase(lyric.size() - 2, lyric.size());
                lyric += " that" + reason.at(1).substr(2, 99);
            }
        }
        if (index == 8) {
            break;
        }
    }
    return lyric;
}

std::string verses(size_t index_1, size_t index_2) {
    std::string lyrics{};
    for(size_t i{index_1}; i <= index_2; ++i) {
        lyrics += verse(i) + "\n";
    }
    return lyrics;
}

}  // namespace food_chain
