#include "series.h"

namespace series {

// TODO: add your solution here
std::vector<std::string> slice(std::string sequence, size_t length) {
    std::vector<std::string> sequences;
    std::string slice;
    size_t size{sequence.size()};
    if (size < length || length < 1) {
        throw std::domain_error("ERROR slice bigger then sequence.");
    }
    for (size_t i{length - 1}; i < size; ++i) {
        slice.clear();
        for (size_t j{i - (length - 1)}; j <= i; ++j) {
            slice.push_back(sequence.at(j));
        }
        sequences.emplace_back(slice);
    }
    return sequences;
}

}  // namespace series
