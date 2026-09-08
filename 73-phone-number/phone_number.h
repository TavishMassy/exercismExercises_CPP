#pragma once
#include <string>
#include <stdexcept>

namespace phone_number {

// TODO: add your solution here
class phone_number{
    private:
        std::string _number;

    public:
        phone_number(std::string number);
        std::string number() { return _number; }
};

}  // namespace phone_number
