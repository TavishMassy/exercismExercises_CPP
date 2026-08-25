#pragma once

namespace space_age {

// TODO: add your solution here
class space_age{
    private:
        long long age_in_seconds{0};
    public:
        explicit space_age(long long age_in_seconds) : age_in_seconds(age_in_seconds) {}

        long long seconds() const;

        long double on_earth() const;

        long double on_mercury() const;

        long double on_venus() const;

        long double on_mars() const;

        long double on_jupiter() const;

        long double on_saturn() const;

        long double on_uranus() const;
 
        long double on_neptune() const;
};

}  // namespace space_age
