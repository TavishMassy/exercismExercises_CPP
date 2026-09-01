#include "perfect_numbers.h"

namespace perfect_numbers {

classification classify(int num) {
    if (num <= 0) throw std::domain_error("Zero or Negative integer is rejected.");
    int sum{0};
    for (int i{1}; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) return classification::perfect;
    else if (sum < num) return classification::deficient;
    else return classification::abundant;
}
    
}  // namespace perfect_numbers
