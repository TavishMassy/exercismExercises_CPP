#include "isogram.h"

namespace isogram {

// TODO: add your solution here
bool is_isogram(std::string text) {
    for (char &c : text) {
        c = tolower(c);
    }
    while (text.length() != 0) {
        char c{text.back()};
        text.pop_back();
        if (isalpha(c)) {    
            if (text.find(c) != std::string::npos) {
                return false;
            }
        }
    }
    return true;
}

}  // namespace isogram
