#include "queen_attack.h"

namespace queen_attack {

// TODO: add your solution here
chess_board::chess_board(std::pair<int, int>  white, std::pair<int, int> black) {
    if (!_is_valid_positon(white.first)) throw std::domain_error("");
    if (!_is_valid_positon(white.second)) throw std::domain_error("");
    if (!_is_valid_positon(black.first)) throw std::domain_error("");
    if (!_is_valid_positon(black.second)) throw std::domain_error("");
    if (white == black) throw std::domain_error("");
    _white = white;
    _black = black;
}

bool chess_board::_is_valid_positon(int num) {
    if (num < 0 || num > 7) return false;
    return true;
}

bool chess_board::can_attack() const {
    if (_white.first == _black.first || _white.second == _black.second) return true;

    if (std::abs(_white.first - _black.first) == std::abs(_white.second - _black.second)) {
        return true;
    }
    return false;
}

}  // namespace queen_attack
