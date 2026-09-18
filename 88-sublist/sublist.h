#pragma once
#include <vector>

namespace sublist {

// TODO: add your solution here
enum class List_comparison {
    equal,
    sublist,
    superlist,
    unequal
};

List_comparison sublist(std::vector<int> list_a, std::vector<int> list_b);

}  // namespace sublist
