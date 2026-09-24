#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H
#include <stdexcept>
#include <numeric>
#include <string>

namespace affine_cipher {

// TODO: add your solution here
std::string encode(std::string text, int a, int b);
std::string decode(std::string text, int a, int b);

}  // namespace affine_cipher

#endif  // AFFINE_CIPHER_H
