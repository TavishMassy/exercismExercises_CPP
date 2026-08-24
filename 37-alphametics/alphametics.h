#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H
#include <string>
#include <vector>
#include <optional>
#include <unordered_map>

namespace alphametics {

// TODO: add your solution here
inline std::vector<int> numbers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
std::optional<std::unordered_map<char, int>> solve(std::string equation);
void _words_to_weights(const std::vector<std::string>& words, const std::string& end_word, std::unordered_map<char, long long>& weights);
bool _check_combination(const std::unordered_map<char, long long>& weights, const std::unordered_map<char, int>& encodings);
bool _combinations(size_t i, const std::string& found, const std::vector<int>& char_start, std::unordered_map<char, int>& encodings, const std::unordered_map<char, long long>& weights, std::vector<bool>& used);

}  // namespace alphametics

#endif  // ALPHAMETICS_H
