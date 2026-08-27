#include "grade_school.h"

namespace grade_school {

// TODO: add your solution here
std::map<int, std::vector<std::string>> school::roster() const {
    return school_;
}

void school::add(std::string name, int grade) {
    try {
        std::vector<std::string> &students{school_.at(grade)};
        for (auto at{students.begin()}; at != students.end(); ++at) {
            if (*at == name) return;
            if (*at > name) {
                students.insert(at, name);
                return;
            }
        }
        students.emplace_back(name);
    } catch (...) {
        school_.insert({grade,{name}});
    }
}

std::vector<std::string> school::grade(int grade) const {
    try {
        return school_.at(grade);
    } catch (...) {
        return {};
    }
}

}  // namespace grade_school
