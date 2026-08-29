#include "secret_handshake.h"

namespace secret_handshake {

// TODO: add your solution here
std::vector<std::string> commands(int commands) {
    std::vector<std::string> instructions{};
    for (size_t i{0}; i != codes.size(); ++i) {
        if (commands & codes.at(i)) {
            if (!(codes.at(i) & 0b10000)) instructions.emplace_back(actions.at(i));
            else _reverse(instructions);
        }
    }
    return instructions;
}

void _reverse(std::vector<std::string> &instructions) {
    size_t left = 0;
    size_t right = instructions.size();
    if (right > 0) {
        --right;
        while (left < right) {
            std::swap(instructions.at(left), instructions.at(right));
            ++left;
            --right;
        }
    }
}

}  // namespace secret_handshake
