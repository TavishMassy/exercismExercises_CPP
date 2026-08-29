#include "sum_of_multiples.h"

namespace sum_of_multiples {

// TODO: add your solution here
int to(std::vector<int> multiples, int till) {
    int sum{0};
    for (int i{0}; i < till; ++i) {
        for (int multiple : multiples) {
            if (multiple != 0 && i % multiple == 0) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}

}  // namespace sum_of_multiples
