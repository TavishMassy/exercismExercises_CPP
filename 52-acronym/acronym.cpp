#include "acronym.h"

namespace acronym {

// TODO: add your solution here
std::string acronym(std::string text) {
    std::string acronym;
    if (isalpha(text.at(0))) acronym.push_back(toupper(text.at(0)));
    for (size_t i{1}; i < text.length(); ++i) {
        if (!isalpha(text.at(i - 1)) && text.at(i - 1) != '\'') {
            if (isalpha(text.at(i))) acronym.push_back(toupper(text.at(i)));
        }
    }
    return acronym;
}

}  // namespace acronym
