#pragma once
#include <vector>

namespace knapsack {

struct Item {
    int weight;
    int value;
};
// int sum_value(const std::vector<Item>& combination);
// std::vector<Item> _selected_items(int max_weight, std::vector<Item> items);
int maximum_value(int max_weight, std::vector<Item> items);

}  // namespace knapsack
