#include "list_ops.h"

namespace list_ops {

// TODO: add your solution here
void append(std::vector<int>& left, std::vector<int>& right) {
    for (int element : right) {
        left.push_back(element);
    }
}

std::vector<int> concat(std::vector<std::vector<int>>& input) {
    std::vector<int> combined_list;
    for (std::vector<int> list : input) {
        for (int element : list) {
            combined_list.emplace_back(element);
        }
    }
    return combined_list;
}

std::vector<std::vector<int>> concat(std::vector<std::vector<std::vector<int>>>& input) {
    std::vector<std::vector<int>> combined_list;
    for (std::vector<std::vector<int>> super_list : input) {
        for (std::vector<int> sub_list : super_list) {   
            combined_list.emplace_back(sub_list);
        }
    }
    return combined_list;
}

std::vector<int> reverse(std::vector<int>& input) {
    std::vector<int> output;
    for (auto it{input.rbegin()}; it != input.rend(); ++it) {
        output.emplace_back(*it);
    }
    return output;
}

std::vector<std::vector<int>> reverse(std::vector<std::vector<int>>& input) {
    std::vector<std::vector<int>> output;
    for (auto it{input.rbegin()}; it != input.rend(); ++it) {
        output.emplace_back(*it);
    }
    return output;
}

}  // namespace list_ops
