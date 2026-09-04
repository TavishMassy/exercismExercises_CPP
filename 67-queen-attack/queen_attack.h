#pragma once
#include <stdexcept>
#include <utility>

namespace queen_attack {

// TODO: add your solution here
class chess_board{
private:
    std::pair<int, int> _white;
    std::pair<int, int> _black;    

public:
    chess_board(std::pair<int, int> white,std::pair<int, int> black);
    bool _is_valid_positon(int);

    std::pair<int, int> white() const { return _white; }
    std::pair<int, int> black() const { return _black; }

    bool can_attack() const;

};

}  // namespace queen_attack
