#include "run_length_encoding.h"

namespace run_length_encoding {

// TODO: add your solution here
std::string encode(std::string text) {
    std::string encoded;
    int count{1};
    int length{static_cast<int>(text.length())};
    for (int i{1}; i < length; ++i) {
        char c = text.at(i - 1);
        if(c == text.at(i)) {
            ++count;
        } else {
            _add_to_encoded(count, encoded, c);
            count = 1;
        }
        if (i == length - 1) {
            c = text.at(i);
            _add_to_encoded(count, encoded, c);
        } 
    }
    return encoded;
}

void _add_to_encoded(int count, std::string& encoded, char c) {
    if (count > 1) {
        encoded += std::to_string(count) + c;
        count = 1;
    } else {
        encoded += c;
    }
}

std::string decode(std::string text) {
    std::string decoded;
    int count{0};
    int length{static_cast<int>(text.length())};
    for (int i{1}; i < length; ++i) {
        char c = text.at(i - 1);
        if(c >= '0' && c <= '9') {
            count *= 10;
            count += c - '0';
        } else if (i == 1) {
            count = 1;
            if (count > 0) decoded.append(count, c);
            count = 0;
        }
        c = text.at(i);
        if (!(c >= '0' && c <= '9')) {
            if (count == 0) count = 1;
            if (count > 0) decoded.append(count, c);
            count = 0;
        }
    }
    return decoded;
}

}  // namespace run_length_encoding
