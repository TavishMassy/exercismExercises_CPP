#include "knapsack.h"

namespace knapsack {

// TODO: add your solution here
int maximum_value(int max_weight, std::vector<Item> items) {
    // Create a 1D DP array initialized to 0 for all capacities
    std::vector<int> dp(max_weight + 1, 0);

    // Loop through each item in the list
    for (const Item& item : items) {
        // Loop backwards through the DP array to avoid reusing the same item
        for (int w = max_weight; w >= item.weight; --w) {
            // Choose the max between leaving the item or taking it
            dp[w] = std::max(dp[w], dp[w - item.weight] + item.value);
        }
    }

    // The final high score is at the end of the array
    return dp[max_weight];
}

// int sum_value(const std::vector<Item>& combination) {
//     int total{0};
//     for (const Item& item : combination) {
//         total += item.value;
//     }
//     return total;
// }

// // Your recursive function, adapted to explore all combinations
// std::vector<Item> _selected_items(int max_weight, std::vector<Item> items) {
//     // Base case: bag is full or no items left
//     if (max_weight <= 0 || items.empty()) {
//         return {};
//     }

//     // Isolate the current item and remove it from the remaining pool
//     Item current = items.back();
//     items.pop_back();

//     // UNIVERSE A: Leave the item.
//     // Recurse to find the best combination of the remaining items.
//     std::vector<Item> leave_combo = _selected_items(max_weight, items);

//     // UNIVERSE B: Take the item (only if it fits).
//     std::vector<Item> take_combo;
//     if (current.weight <= max_weight) {
//         // Recurse to find the best combination for the LEFTOVER weight
//         take_combo = _selected_items(max_weight - current.weight, items);
//         // Add our current item into this combination
//         take_combo.push_back(current);
//     }

//     // Compare all combinations and return the winner
//     if (sum_value(take_combo) > sum_value(leave_combo)) {
//         return take_combo;
//     } else {
//         return leave_combo;
//     }
// }

// int maximum_value(int max_weight, std::vector<Item> items) {
//     // Get the absolute best combination back from the recursion tree
//     std::vector<Item> best_selection = _selected_items(max_weight, items);
    
//     // Sum it up (exactly like your original code did)
//     return sum_value(best_selection);
// }

}  // namespace knapsack
