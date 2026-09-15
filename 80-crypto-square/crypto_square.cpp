#include "crypto_square.h"

namespace crypto_square {

// TODO: add your solution here
cipher::cipher(std::string text) {
    std::string clean_text;
    for (char c : text) {
        if(isalnum(c)) {
            c = tolower(c);
            clean_text.push_back(c);
        }
    }
    _clean_text = clean_text;
}

std::string cipher::normalized_cipher_text() {
    size_t text_length{_clean_text.length()};
    if (text_length < 3) {
        _ciphered_text = _clean_text;
        return _ciphered_text;
    }
    size_t row{0};
    size_t column;
    while ((row + 1) * (row + 1) < text_length) {
        ++row;
    }
    column = row;
    while (row * column < text_length) {
        if (row < column) {
            ++row;
        } else {
            ++column;
        }
    }
    size_t grid_length{(row * column)};
    while (_clean_text.length() < grid_length) {
        _clean_text += " ";
    }
    _ciphered_text = "";
    for (size_t i{0}; i < column; ++i) {
        for (size_t j{0}; j < row; ++j) {
            _ciphered_text.push_back(_clean_text.at(i + (j * column)));
        }
        _ciphered_text += ' ';
    }
    if (!_ciphered_text.empty()) {
        _ciphered_text.pop_back();
    }
    return _ciphered_text;
}

}  // namespace crypto_square
