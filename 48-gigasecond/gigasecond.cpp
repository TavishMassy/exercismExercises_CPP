#include "gigasecond.h"

namespace gigasecond {

// TODO: add your solution here
boost::posix_time::ptime advance(boost::posix_time::ptime start_date) {
    return start_date + boost::posix_time::seconds(1000000000);
}

}  // namespace gigasecond
