#include "meetup.h"

namespace meetup {

// TODO: add your solution here
scheduler::scheduler(boost::gregorian::months_of_year month, int year)
    : month_(month), year_(year) {}

// --- Private Helpers ---

boost::gregorian::date scheduler::teenth(int day_of_week) const {
    return find_date(13, 19, day_of_week);
}

boost::gregorian::date scheduler::nth(int n, int day_of_week) const {
    int start_day = 1 + (n - 1) * 7;
    return find_date(start_day, start_day + 6, day_of_week);
}

boost::gregorian::date scheduler::last(int day_of_week) const {
    int last_day = boost::gregorian::gregorian_calendar::end_of_month_day(year_, month_);
    return find_date(last_day - 6, last_day, day_of_week);
}

boost::gregorian::date scheduler::find_date(int start, int end, int target_weekday) const {
    for (int d = start; d <= end; ++d) {
        boost::gregorian::date current_date(year_, month_, d);
        if (current_date.day_of_week() == target_weekday) {
            return current_date;
        }
    }
    return {};
}

}  // namespace meetup
