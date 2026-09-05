#pragma once
#include <string>

namespace date_independent {

// TODO: add your solution here
class clock {
private:
    int total_minutes; 
    
    clock(int minutes) : total_minutes(minutes) {}

public:
    static clock at(int hours, int minutes);

    clock plus(int minutes) const { return at(0, total_minutes + minutes); }

    explicit operator std::string() const;

    bool operator==(const clock& other) const;
    bool operator!=(const clock& other) const;
    
};

}  // namespace date_independent
