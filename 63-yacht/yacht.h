#pragma once
#include <map>
#include <string>
#include <vector>

namespace yacht {

// TODO: add your solution here
const std::map<std::string, int> choices{
    {"ones", 0},    
    {"twos", 1},    
    {"threes", 2},    
    {"fours", 3}, 
    {"fives", 4},  
    {"sixes", 5},  
    {"full house", 6},  
    {"four of a kind", 7},
    {"little straight", 8}, 
    {"big straight", 9},
    {"choice", 10}, 
    {"yacht", 11}
};

int score(std::vector<int>, std::string);

}  // namespace yacht
