#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

// TODO: add your solution here
class scheduler {
public:
    scheduler(boost::gregorian::months_of_year month, int year);

    // "Teenth" days (13th through 19th)
    boost::gregorian::date monteenth() const { return teenth(boost::gregorian::Monday); }
    boost::gregorian::date tuesteenth() const { return teenth(boost::gregorian::Tuesday); }
    boost::gregorian::date wednesteenth() const { return teenth(boost::gregorian::Wednesday); }
    boost::gregorian::date thursteenth() const { return teenth(boost::gregorian::Thursday); }
    boost::gregorian::date friteenth() const { return teenth(boost::gregorian::Friday); }
    boost::gregorian::date saturteenth() const { return teenth(boost::gregorian::Saturday); }
    boost::gregorian::date sunteenth() const { return teenth(boost::gregorian::Sunday); }

    // First occurrences
    boost::gregorian::date first_monday() const { return nth(1, boost::gregorian::Monday); }
    boost::gregorian::date first_tuesday() const { return nth(1, boost::gregorian::Tuesday); }
    boost::gregorian::date first_wednesday() const { return nth(1, boost::gregorian::Wednesday); }
    boost::gregorian::date first_thursday() const { return nth(1, boost::gregorian::Thursday); }
    boost::gregorian::date first_friday() const { return nth(1, boost::gregorian::Friday); }
    boost::gregorian::date first_saturday() const { return nth(1, boost::gregorian::Saturday); }
    boost::gregorian::date first_sunday() const { return nth(1, boost::gregorian::Sunday); }

    // Second occurrences
    boost::gregorian::date second_monday() const { return nth(2, boost::gregorian::Monday); }
    boost::gregorian::date second_tuesday() const { return nth(2, boost::gregorian::Tuesday); }
    boost::gregorian::date second_wednesday() const { return nth(2, boost::gregorian::Wednesday); }
    boost::gregorian::date second_thursday() const { return nth(2, boost::gregorian::Thursday); }
    boost::gregorian::date second_friday() const { return nth(2, boost::gregorian::Friday); }
    boost::gregorian::date second_saturday() const { return nth(2, boost::gregorian::Saturday); }
    boost::gregorian::date second_sunday() const { return nth(2, boost::gregorian::Sunday); }

    // Third occurrences
    boost::gregorian::date third_monday() const { return nth(3, boost::gregorian::Monday); }
    boost::gregorian::date third_tuesday() const { return nth(3, boost::gregorian::Tuesday); }
    boost::gregorian::date third_wednesday() const { return nth(3, boost::gregorian::Wednesday); }
    boost::gregorian::date third_thursday() const { return nth(3, boost::gregorian::Thursday); }
    boost::gregorian::date third_friday() const { return nth(3, boost::gregorian::Friday); }
    boost::gregorian::date third_saturday() const { return nth(3, boost::gregorian::Saturday); }
    boost::gregorian::date third_sunday() const { return nth(3, boost::gregorian::Sunday); }

    // Fourth occurrences
    boost::gregorian::date fourth_monday() const { return nth(4, boost::gregorian::Monday); }
    boost::gregorian::date fourth_tuesday() const { return nth(4, boost::gregorian::Tuesday); }
    boost::gregorian::date fourth_wednesday() const { return nth(4, boost::gregorian::Wednesday); }
    boost::gregorian::date fourth_thursday() const { return nth(4, boost::gregorian::Thursday); }
    boost::gregorian::date fourth_friday() const { return nth(4, boost::gregorian::Friday); }
    boost::gregorian::date fourth_saturday() const { return nth(4, boost::gregorian::Saturday); }
    boost::gregorian::date fourth_sunday() const { return nth(4, boost::gregorian::Sunday); }

    // Last occurrences
    boost::gregorian::date last_monday() const { return last(boost::gregorian::Monday); }
    boost::gregorian::date last_tuesday() const { return last(boost::gregorian::Tuesday); }
    boost::gregorian::date last_wednesday() const { return last(boost::gregorian::Wednesday); }
    boost::gregorian::date last_thursday() const { return last(boost::gregorian::Thursday); }
    boost::gregorian::date last_friday() const { return last(boost::gregorian::Friday); }
    boost::gregorian::date last_saturday() const { return last(boost::gregorian::Saturday); }
    boost::gregorian::date last_sunday() const { return last(boost::gregorian::Sunday); }

private:
    boost::gregorian::months_of_year month_;
    int year_;

    // Helpers to find the exact dates
    boost::gregorian::date teenth(int day_of_week) const;
    boost::gregorian::date nth(int n, int day_of_week) const;
    boost::gregorian::date last(int day_of_week) const;
    boost::gregorian::date find_date(int start, int end, int target_weekday) const;
};

}  // namespace meetup
