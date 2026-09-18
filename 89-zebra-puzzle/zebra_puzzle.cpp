#include "zebra_puzzle.h"
#include <algorithm>
#include <vector>

namespace zebra_puzzle {

enum Nation { ENGLISH, SPANIARD, UKRAINIAN, NORWEGIAN, JAPANESE };
enum Color { RED, GREEN, IVORY, YELLOW, BLUE };
enum Drink { COFFEE, TEA, MILK, ORANGE_JUICE, WATER };
enum Hobby { DANCING, PAINTING, READING, FOOTBALL, CHESS };
enum Pet { DOG, SNAIL, FOX, HORSE, ZEBRA };

Solution solve() {
    std::vector<std::string> names = {"Englishman", "Spaniard", "Ukrainian", "Norwegian", "Japanese"};
    
    std::vector<int> colors = {0, 1, 2, 3, 4};
    std::vector<int> nations = {0, 1, 2, 3, 4};
    std::vector<int> drinks = {0, 1, 2, 3, 4};
    std::vector<int> hobbies = {0, 1, 2, 3, 4};
    std::vector<int> pets = {0, 1, 2, 3, 4};

    // Permute step-by-step to prune the search space early
    do {
        if (nations[NORWEGIAN] != 0) continue; // Rule 10: Norwegian in first house

        do {
            if (colors[BLUE] != 1) continue; // Rule 15: Norwegian next to blue
            if (colors[RED] != nations[ENGLISH]) continue; // Rule 2: Englishman in red
            if (colors[GREEN] != colors[IVORY] + 1) continue; // Rule 6: Green right of Ivory

            do {
                if (drinks[MILK] != 2) continue; // Rule 9: Middle drinks milk
                if (drinks[COFFEE] != colors[GREEN]) continue; // Rule 4: Coffee in green
                if (drinks[TEA] != nations[UKRAINIAN]) continue; // Rule 5: Ukrainian drinks tea

                do {
                    if (hobbies[PAINTING] != colors[YELLOW]) continue; // Rule 8: Painter in yellow
                    if (hobbies[FOOTBALL] != drinks[ORANGE_JUICE]) continue; // Rule 13: Football drinks OJ
                    if (hobbies[CHESS] != nations[JAPANESE]) continue; // Rule 14: Japanese plays chess

                    do {
                        if (pets[DOG] != nations[SPANIARD]) continue; // Rule 3: Spaniard owns dog
                        if (pets[SNAIL] != hobbies[DANCING]) continue; // Rule 7: Snail owner dances
                        
                        // Rule 11: Reader next to fox
                        if (std::abs(hobbies[READING] - pets[FOX]) != 1) continue;
                        // Rule 12: Painter next to horse
                        if (std::abs(hobbies[PAINTING] - pets[HORSE]) != 1) continue;

                        // Found the single valid layout!
                        Solution sol;
                        for (int i = 0; i < 5; ++i) {
                            if (drinks[WATER] == nations[i]) sol.drinksWater = names[i];
                            if (pets[ZEBRA] == nations[i]) sol.ownsZebra = names[i];
                        }
                        return sol;

                    } while (std::next_permutation(pets.begin(), pets.end()));
                } while (std::next_permutation(hobbies.begin(), hobbies.end()));
            } while (std::next_permutation(drinks.begin(), drinks.end()));
        } while (std::next_permutation(colors.begin(), colors.end()));
    } while (std::next_permutation(nations.begin(), nations.end()));

    return {"", ""};
}

}  // namespace zebra_puzzle
