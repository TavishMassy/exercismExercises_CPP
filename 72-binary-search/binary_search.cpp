#include "binary_search.h"

namespace binary_search {

// TODO: add your solution here
std::size_t find(const std::vector<int>& data, int key) {
    std::size_t mid;
    std::size_t low{0}; 
    std::size_t high{data.size()};
    int curr;
    while (low < high) {
        mid = low + ((high - low) / 2);
        curr = data.at(mid);
        if (curr == key) {
            return mid;
        } else if (curr > key) {
            high = mid;
        } else {
            low = mid + 1;
        }   
    }
    throw std::domain_error("");
}

}  // namespace binary_search
