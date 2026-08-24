#include "alphametics.h"

namespace alphametics {

// TODO: add your solution here
std::optional<std::unordered_map<char, int>> solve(std::string equation) {
    std::string word;
    std::string found;
    std::string end_word;
    std::vector<int> char_start;
    std::vector<std::string> words;
    std::unordered_map<char, long long> weights;
    std::unordered_map<char, int> encodings;
    
    for (size_t i = 0; i < equation.size(); ++i) {
        char c = equation[i];
        if (std::isalpha(c)) {
            c = static_cast<char>(std::toupper(c));
            word += c;
            if (found.find(c) == std::string::npos) {
                found += c;
                char_start.push_back(0);
            }
            if (word.length() == 1) {
                char_start[found.find(c)] = 1;
            }
        } else if (c == '+' || c == '=') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    
    if (!word.empty()) {
        end_word = word;
    } else if (!words.empty()) {
        end_word = words.back();
        words.pop_back();
    }

    if (found.size() > 10) {
        return std::nullopt;
    }

    _words_to_weights(words, end_word, weights);
    std::vector<bool> used(10, false);
    
    if (_combinations(0, found, char_start, encodings, weights, used)) {
        return encodings;
    }
    
    return std::nullopt;
}

void _words_to_weights(const std::vector<std::string>& words, const std::string& end_word, std::unordered_map<char, long long>& weights) {
    for (const std::string& w : words) {
        long long power = 1;
        for (int i = static_cast<int>(w.length()) - 1; i >= 0; --i) {
            weights[w[i]] += power;
            power *= 10;
        }
    }
    long long power = 1;
    for (int i = static_cast<int>(end_word.length()) - 1; i >= 0; --i) {
        weights[end_word[i]] -= power;
        power *= 10;
    }
}

bool _check_combination(const std::unordered_map<char, long long>& weights, const std::unordered_map<char, int>& encodings) {
    long long sum = 0;
    for (const auto& pair : weights) {
        sum += pair.second * encodings.at(pair.first);
    }
    return sum == 0;
}

bool _combinations(size_t i, const std::string& found, const std::vector<int>& char_start, std::unordered_map<char, int>& encodings, const std::unordered_map<char, long long>& weights, std::vector<bool>& used) {
    if (i == found.length()) {
        return _check_combination(weights, encodings);
    }

    char c = found[i];
    int start_digit = char_start[i];

    for (int d = start_digit; d <= 9; ++d) {
        if (!used[d]) {
            used[d] = true;
            encodings[c] = d;
            
            if (_combinations(i + 1, found, char_start, encodings, weights, used)) {
                return true;
            }
            
            used[d] = false;
        }
    }
    return false;
}

}  // namespace alphametics
