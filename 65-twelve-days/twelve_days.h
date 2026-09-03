#pragma once
#include <string>
#include <vector>

namespace twelve_days {

// TODO: add your solution here
const std::vector<std::string> lyrics{
    
    " day of Christmas my true love gave to me:",
    " and a Partridge in a Pear Tree.\n",
    " two Turtle Doves,",
    " three French Hens,",
    " four Calling Birds,",
    " five Gold Rings,",
    " six Geese-a-Laying,",
    " seven Swans-a-Swimming,",
    " eight Maids-a-Milking,",
    " nine Ladies Dancing,",
    " ten Lords-a-Leaping,",
    " eleven Pipers Piping,",
    " twelve Drummers Drumming,"
};

const std::vector<std::string> days{
    "On the ",
    "first",
    "second",
    "third",
    "fourth",
    "fifth",
    "sixth",
    "seventh",
    "eighth",
    "ninth",
    "tenth",
    "eleventh",
    "twelfth"
};

std::string recite(int start, int stop);

}  // namespace twelve_days
