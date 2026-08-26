#include "pangram.h"

namespace pangram {

// TODO: add your solution here
bool is_pangram(std::string text) {
    std::string alphas{};
    for (char c : text) {
        c = tolower(c);
        if (isalpha(c) && alphas.find(c) == std::string::npos) {
            alphas.push_back(c);
        }
    }
    if (alphas.length() == 26) {
        return true;
    }
    return false;
}

}  // namespace pangram
