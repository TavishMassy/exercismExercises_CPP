#include "dnd_character.h"

namespace dnd_character {

// TODO: add your solution here
int modifier(int num) {
    return -static_cast<int>(std::ceil((10 - num) / 2.0));
}

int ability() {
    return 3 + rand() % (18 - 3 + 1);
}

}  // namespace dnd_character
