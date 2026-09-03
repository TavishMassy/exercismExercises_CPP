#include "twelve_days.h"

namespace twelve_days {

// TODO: add your solution here
std::string recite(int start, int stop) {
    std::string song{""};
    for (int i{start}; i <= stop; ++i) {
        song += days.at(0);
        song += days.at(i);
        song += lyrics.at(0);
        if (i == 1) {
            song += lyrics.at(1).substr(4, 99);
        } else {
            for (int j{i}; j >= 1; --j) {
                song += lyrics.at(j);
            }
        }
        if (i != stop) {
            song += "\n";
        }
    }
    return song;
}

}  // namespace twelve_days
