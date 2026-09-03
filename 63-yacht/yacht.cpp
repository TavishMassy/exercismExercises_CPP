#include "yacht.h"

namespace yacht {

// TODO: add your solution here
int score(std::vector<int> faces, std::string choice) {
    int total_score{0};
    std::map<int, int> counts{{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
    for (int i : faces) {
        ++counts[i];
    }
    switch (choices.at(choice))
    {
    case 0:
        total_score += counts[1] * 1;
        break;
    
    case 1:
        total_score += counts[2] * 2;
        break;
        
    case 2:
        total_score += counts[3] * 3;
        break;

    case 3:
        total_score += counts[4] * 4;
        break;

    case 4:
        total_score += counts[5] * 5;
        break;

    case 5:
        total_score += counts[6] * 6;
        break;

    case 6:
            for (int i{1}; i < 7; ++i) {
                if (counts[i] == 2) {
                    total_score += i * 2;
                } else if (counts[i] == 3) {
                    total_score += i * 3;
                } else if (counts[i] != 0) {
                    total_score = 0;
                    break;
                }
            }
        break;

    case 7:
        for (int i{1}; i < 7; ++i) {
            if (counts[i] >= 4) {
                total_score += i * 4;
            }
        }
        break;

    case 8:
        for (int i{1}; i < 6; ++i) {
            if (counts[i] == 1) {
                total_score = 30;
            } else {
                total_score = 0;
                break;
            }
        }
        break;

    case 9:
        for (int i{2}; i < 7; ++i) {
            if (counts[i] == 1) {
                total_score = 30;
            } else {
                total_score = 0;
                break;
            }
        }
        break;

    case 10:
        for (int i : faces) {
            total_score += i;
        }
        break;

    case 11:
        for (int i{1}; i < 7; ++i) {
            if (counts[i] == 5) {
                total_score += 50;
            }
        }
        break;
    }
    return total_score;
}

}  // namespace yacht
