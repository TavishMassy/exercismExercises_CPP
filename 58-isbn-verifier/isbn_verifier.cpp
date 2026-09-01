#include "isbn_verifier.h"

namespace isbn_verifier {

// TODO: add your solution here
bool is_valid(std::string id_number) {
    std::string num_found;
    for (char c : id_number) {
        if (isalnum(c)) {
            if (c >= '0' && c <= '9') {
                num_found.push_back(c);
            } else if (c == 'X' || c == 'x') {
                num_found.push_back('X'); 
            } else return false;
        }
    }
    if (num_found.find('X') != std::string::npos && num_found.back() != 'X') return false;
    size_t sum{0};
    size_t size{num_found.size()};
    if (size > 10) return false;
    for (size_t i{0}; i < size; ++i) {
        if (num_found.at(i) == 'X') sum += 10 * (size - i);
        else sum += (num_found.at(i) - '0') * (size - i);
    }
    if(sum > 0 && sum % 11 == 0) return true;
    return false;
}

}  // namespace isbn_verifier
