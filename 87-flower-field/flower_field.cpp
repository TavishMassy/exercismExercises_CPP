#include "flower_field.h"
#include <iostream>

namespace flower_field {

// TODO: add your solution here
std::vector<std::string> annotate(std::vector<std::string> field) {
    size_t count;
    std::vector<std::string> search_box;
    for (size_t i{0}; i < field.size(); ++i) {
        search_box.clear();
        if (i > 0) {
            search_box.push_back(field.at(i - 1));
        }
        search_box.push_back(field.at(i));
        if (i + 1 < field.size()) {
            search_box.push_back(field.at(i + 1));
        }
        for (size_t j{0}; j < field.at(i).length(); ++j) {
            if (field.at(i).at(j) == ' ') {
                count = 0;
                count = _count_in_box(search_box, j);
                if (count > 0) {
                    field.at(i).at(j) = '0' + count;
                }
            }
        }
    }
    return field;
}

size_t _count_in_box(std::vector<std::string>& search_box, size_t column) {
    size_t count{0};
    size_t start, end;
    start = (column > 0) ? column - 1 : 0;
    end = (column + 1 < search_box.at(0).length()) ? column + 1 : column;
    for (std::string& row : search_box) {
        for (size_t i{start}; i <= end; ++i) {
            count = (row.at(i) == '*') ? count + 1 : count;
        }
    }
    return count;
}

}  // namespace flower_field
