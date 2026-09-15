#pragma once
#include <string>

namespace crypto_square {

// TODO: add your solution here
class cipher {
private:
    std::string _clean_text;
    std::string _ciphered_text;
public:
    cipher(std::string text);
    std::string normalized_cipher_text();
};

}  // namespace crypto_square
