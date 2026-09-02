#pragma once
#include <string>

namespace run_length_encoding {

// TODO: add your solution here
std::string encode(std::string);
void _add_to_encoded(int, std::string&, char);

std::string decode(std::string);

}  // namespace run_length_encoding
