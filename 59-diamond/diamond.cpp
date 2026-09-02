#include "diamond.h"

namespace diamond {

// TODO: add your solution here
std::vector<std::string> rows(char C) {
    int n = C - 'A';
    std::vector<std::string> diamond;

    // Generate the top half and the middle row
    for (int i = 0; i <= n; ++i) {
        char curr = 'A' + i;
        std::string row(2 * n + 1, ' ');
        
        if (i == 0) {
            row[n] = 'A';
        } else {
            row[n - i] = curr;
            row[n + i] = curr;
        }
        diamond.push_back(row);
    }

    // Generate the bottom half by mirroring the top half
    for (int i = n - 1; i >= 0; --i) {
        diamond.push_back(diamond[i]);
    }

    return diamond;
}

}  // namespace diamond