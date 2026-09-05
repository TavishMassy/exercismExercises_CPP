#pragma once
#include <string>
#include <unordered_set>

namespace robot_name {

// TODO: add your solution here
inline std::unordered_set<std::string> names{};

class robot{
private:
    std::string _name;

public:
    std::string _create_unique_name();
    robot();

    std::string name() const { return _name; }

    void reset();

};

}  // namespace robot_name
