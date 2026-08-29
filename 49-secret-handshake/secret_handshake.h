#pragma once
#include <string>
#include <vector>

namespace secret_handshake {

// TODO: add your solution here
const std::vector<int> codes{0b00001, 0b00010, 0b00100, 0b01000, 0b10000};
const std::vector<std::string> actions{"wink", "double blink", "close your eyes", "jump", ""};

std::vector<std::string> commands(int commands);
void _reverse(std::vector<std::string> &instructions);

}  // namespace secret_handshake
