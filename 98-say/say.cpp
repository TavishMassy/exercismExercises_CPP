#include "say.h"

namespace say {

// TODO: add your solution here
std::string in_english(long long num) {
    if (num < 0) {
        throw std::domain_error("ERROR: Neative numbers not supported.");
    }
    if (num > 999'999'999'999) {
        throw std::domain_error("ERROR: Num bigger than supported words.");
    }
    std::string word;
    auto _hundredth_word = [](int num) {
        std::string word;
        if (num / 100 > 0) {
            word += ones.at(num / 100) + "hundred ";
            num %= 100;
        }
        if (num == 0) {
            return word;
        }
        if (num <= 19) {
            word += ones.at(num);
        } else {
            word += tens.at(num / 10);
            if (num % 10 > 0) {
                word += "-" + ones.at(num % 10);
            } else {
                word += " ";
            }
        }
        return word;
    };
    if (num / 1'000'000'000 > 0) {
        word += _hundredth_word(num / 1'000'000'000) + "billion ";
        num %= 1'000'000'000;
    }
    if (num / 1'000'000 > 0) {
        word += _hundredth_word(num / 1'000'000) + "million ";
        num %= 1'000'000;
    }
    if (num / 1'000 > 0) {
        word += _hundredth_word(num / 1'000) + "thousand ";
        num %= 1'000;
    }
    if (num == 0 && word.empty()) {
        word += ones.at(num);
    } else if (num > 0) {
        word += _hundredth_word(num);
    }
    while (!word.empty() && word.back() == ' ') {
        word.erase(word.end() - 1);
    }
    return word;
}

}  // namespace say
