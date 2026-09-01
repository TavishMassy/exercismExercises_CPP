#include "scrabble_score.h"

namespace scrabble_score {

// TODO: add your solution here
int score(std::string text) {
    const std::string letters[6] = {"dg", "bcmp", "fhvwy", "k", "jx", "qz"};
    const int scores[6] = {2, 3, 4, 5, 8, 10};
    int score{0};
    for (char c : text) {
        if (isalpha(c)) {
            c = tolower(c);
            for (int i{0}; i < 6; ++i) {
                if (letters[i].find(c) != std::string::npos) {
                    score += scores[i];
                    break;
                } else if (i == 5) ++score;
            }
        }
    }
    return score;
}

}  // namespace scrabble_score
