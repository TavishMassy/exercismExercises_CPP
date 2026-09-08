#include "phone_number.h"

namespace phone_number {

// TODO: add your solution here
phone_number::phone_number(std::string number) {
    for (auto it{number.begin()}; it != number.end();) {
        if (!(*it >= '0' && *it <= '9')) {
            number.erase(it);
        } else {
            ++it;
        }
    }
    if (number.size() == 11) {
        if (number.at(0) != '1') {
            throw std::domain_error("ERROR_A");
        }
        number.erase(number.begin());
    }
    if (number.size() == 10) {
        if (number.at(0) < '2' || number.at(3) < '2') {
            throw std::domain_error("ERROR_B");
        }
    } else {
        throw std::domain_error("ERROR_C");
    }

    _number = number;
}

}  // namespace phone_number
