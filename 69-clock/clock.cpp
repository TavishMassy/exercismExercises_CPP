#include "clock.h"

namespace date_independent {

// TODO: add your solution here
clock clock::at(int hours, int minutes) {
    int minutes_in_day{24 * 60};
    int total{(hours * 60) + minutes};
    return clock(((total % minutes_in_day) + minutes_in_day) % minutes_in_day);
}

clock::operator std::string() const {
    int hours{total_minutes / 60};
    int minutes{total_minutes % 60};
    std::string clock_str{""};
    if (hours < 10) {
        clock_str += '0';
    }
    clock_str += std::to_string(hours) + ':';
    if (minutes < 10) {
        clock_str += '0';
    }
    clock_str += std::to_string(minutes);
    return clock_str;
}

bool clock::operator==(const clock& other) const {
    return total_minutes == other.total_minutes;
}

bool clock::operator!=(const clock& other) const {
    return total_minutes != other.total_minutes;
}

}  // namespace date_independent
