#include "collatz_conjecture.h"

namespace collatz_conjecture {

// TODO: add your solution here
int steps(int num) {
    if (num < 1) throw std::domain_error("");
    int steps{0};
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num *= 3;
            ++num;
        }
        ++steps;
    }
    return steps;
}

}  // namespace collatz_conjecture
