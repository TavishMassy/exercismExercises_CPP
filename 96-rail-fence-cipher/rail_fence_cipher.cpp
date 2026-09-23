#include "rail_fence_cipher.h"
#include <vector>

namespace rail_fence_cipher {

std::string encode(const std::string& plaintext, int num_rails) {
    if (num_rails < 2 or plaintext.length() <= 2) {
        return plaintext;
    }
    std::string encoded;
    std::vector<std::pair<int, char>> tracks;
    std::pair<int, bool> j{0, true};
    for (size_t i{0}; i < plaintext.length(); ++i) {
        tracks.push_back({j.first, plaintext.at(i)});
        if (j.first == 0 && j.second == false) {
            j.second = true;
        } else if (j.first == num_rails - 1 && j.second == true) {
            j.second = false;
        }
        if (j.second) {
            ++j.first;
        } else {
            --j.first;
        }
    }
    for(int i{0}; i < num_rails; ++i) {
        for (std::pair<int, char> track : tracks) {
            if (track.first == i) {
                encoded.push_back(track.second);
            }
        }
    }
    return encoded;
}

std::string decode(const std::string& ciphertext, int num_rails) {
    if (num_rails < 2 || ciphertext.length() <= 2) {
        return ciphertext;
    }
    std::vector<std::string> rails(num_rails);
    int current_rail = 0;
    bool going_down = false;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        rails[current_rail].push_back('*');
        if (current_rail == 0 || current_rail == num_rails - 1) {
            going_down = !going_down;
        }
        current_rail += going_down ? 1 : -1;
    }
    size_t char_index = 0;
    for (int r = 0; r < num_rails; ++r) {
        for (size_t c = 0; c < rails[r].size(); ++c) {
            rails[r][c] = ciphertext[char_index++];
        }
    }
    std::string decoded;
    current_rail = 0;
    going_down = false;
    std::vector<size_t> rail_indices(num_rails, 0);
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        decoded.push_back(rails[current_rail][rail_indices[current_rail]++]);
        if (current_rail == 0 || current_rail == num_rails - 1) {
            going_down = !going_down;
        }
        current_rail += going_down ? 1 : -1;
    }

    return decoded;
}

}  // namespace rail_fence_cipher
