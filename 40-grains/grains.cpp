#include "grains.h"

namespace grains {

// TODO: add your solution here
unsigned long long square(int n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 * square(n - 1);
    }
}

unsigned long long total() {
    unsigned long long total{0};
    for (int i{1}; i <= 64; ++i) {
        total += square(i);
    }
    return total;
}

}  // namespace grains
