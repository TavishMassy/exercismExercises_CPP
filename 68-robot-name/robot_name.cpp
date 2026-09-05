#include "robot_name.h"

namespace robot_name {

// TODO: add your solution here
std::string robot::_create_unique_name() {
    std::string name{""};
    while (name == "") {
        name += static_cast<char>('A' + (rand() % 26));
        name += static_cast<char>('A' + (rand() % 26));    
        name += static_cast<char>('0' + (rand() % 10));
        name += static_cast<char>('0' + (rand() % 10));
        name += static_cast<char>('0' + (rand() % 10));        
        if (names.find(name) != names.end()) {
            name = "";
        } else names.emplace(name);
    }
    return name;
}

robot::robot() {
    _name = _create_unique_name();
}

void robot::reset() {
    _name = _create_unique_name();
}

}  // namespace robot_name
