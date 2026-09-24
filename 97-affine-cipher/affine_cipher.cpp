#include "affine_cipher.h"

namespace affine_cipher {

// TODO: add your solution here
std::string encode(std::string text, int a, int b) {
    if (std::gcd(a, 26) != 1) {
        throw std::invalid_argument("ERROR: Key 1 (i.e., a) is not a coprime of 26.");
    }
    std::string encoded;
    auto _char_encode = [a, b](char c) {
        if (isalpha(c)) {
            c = tolower(c);
            return static_cast<char>((((a * (c - 'a')) + b) % 26) + 'a');
        } else {
            return c;
        }
    };
    for (char& c : text) {
        if (isalnum(c)) {
            encoded.push_back(_char_encode(c));
        }
        if (encoded.length() % 6 == 5) {
            encoded.push_back(' ');
        }
    }
    if (encoded.back() == ' ') {
        encoded.pop_back();
    }
    return encoded;
}

std::string decode(std::string text, int a, int b) {
    if (std::gcd(a, 26) != 1) {
        throw std::invalid_argument("ERROR: Key 1 (i.e., a) is not a coprime of 26.");
    }
    int mmi = 0;
    for (int x = 1; x < 26; ++x) {
        if ((a * x) % 26 == 1) {
            mmi = x;
            break;
        }
    }
    std::string decoded;
    auto _char_encode = [a, b, mmi](char c) {
        c = tolower(c);
        
        int val{mmi * (c - 'a' - b)};
        while (val < 0) val += 26;
        return static_cast<char>((val % 26) + 'a');
    };
    for (char& c : text) {
        if (isalpha(c)) {
            decoded.push_back(_char_encode(c));
        } else if (isalnum(c)) decoded.push_back(c);
    }
    return decoded;
} 

}  // namespace affine_cipher
