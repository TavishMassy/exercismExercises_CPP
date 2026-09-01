#include "pascals_triangle.h"

namespace pascals_triangle {

// TODO: add your solution here
std::vector<std::vector<int>> generate_rows(size_t size) {
    std::vector<std::vector<int>> triangle;
    if(size == 0) return triangle;
    if (size >= 1) triangle.push_back({1});
    if (size >= 2) triangle.push_back({1, 1});
    while (triangle.size() != size) {
        std::vector<int> last_arr{triangle.back()};
        std::vector<int> new_arr{};
        for (size_t i{1}; i < last_arr.size(); ++i) {
            if (new_arr.size() == 0) new_arr.emplace_back(1);
            new_arr.emplace_back(last_arr.at(i - 1) + last_arr.at(i));
        }
        new_arr.emplace_back(1);
        triangle.emplace_back(new_arr);
    }
    return triangle;
}

}  // namespace pascals_triangle
