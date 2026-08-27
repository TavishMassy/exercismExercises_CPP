#pragma once
#include <map>
#include <string>
#include <vector>

namespace grade_school {

// TODO: add your solution here
struct school {
    std::map<int, std::vector<std::string>> school_{};

    std::map<int, std::vector<std::string>> roster() const;

    void add(std::string name, int grade);

    std::vector<std::string> grade(int grade) const;
};

}  // namespace grade_school
