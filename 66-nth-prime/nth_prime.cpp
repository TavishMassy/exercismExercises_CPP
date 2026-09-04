#include "nth_prime.h"

namespace nth_prime {

// TODO: add your solution here
int nth(size_t index) {
    if (index < 1) throw std::domain_error("");
    if (index - 1 < primes.size()) return primes.at(index - 1);
    else {
        int num{primes.back() + 1};
        while (primes.size() < index) {
            int sqrt{static_cast<int>(std::ceil(std::sqrt(num)))};
            primes.emplace_back(num);
            for (int i : primes) {
                if (i > sqrt) {
                    ++num;
                    break;
                }
                if (num % i == 0) {
                    primes.pop_back();
                    ++num;
                    break;
                }
            }
        }
    }
    return primes.at(index - 1);
}

}  // namespace nth_prime
