#pragma once
#include <functional>
#include <vector>
#include <iostream>

namespace list_ops {

// TODO: add your solution here
std::vector<int> reverse(std::vector<int>& input);
std::vector<std::vector<int>> reverse(std::vector<std::vector<int>>& input);

void append(std::vector<int>& left, std::vector<int>& right);

std::vector<int> concat(std::vector<std::vector<int>>& input);
std::vector<std::vector<int>> concat(std::vector<std::vector<std::vector<int>>>& input);

template <typename F>
std::vector<int> filter(std::vector<int>& input, F lambda_func) {
    std::vector<int> output;
    for (int element : input) {
        if (lambda_func(element)) {
            output.emplace_back(element);
        }
    }
    return output;
}

inline size_t length(std::vector<int> input) {
    return input.size();
}

template <typename F>
std::vector<int> map(std::vector<int>& input, F lambda_func) {
    std::vector<int> output;
    for (int element : input) {
        output.emplace_back(lambda_func(element));
    }
    return output;
}

template <typename F>
int foldl(std::vector<int>& input, int num, F lambda_func) {
    if (!input.empty()) {
        for (int element : input) {
            num = lambda_func(num, element);
        }
    }
    return num;
}

template <typename F>
double foldl(std::vector<double>& input, double num, F lambda_func) {
    if (!input.empty()) {
        for (double element : input) {
            num = lambda_func(num, element);
        }
    }
    return num;
}

template <typename F>
int foldr(std::vector<int>& input, int num, F lambda_func) {
    if (!input.empty()) {
        for (auto it{input.rbegin()}; it != input.rend(); ++it) {
            num = lambda_func(num, *it);
        }
    }
    return num;
}

template <typename F>
double foldr(std::vector<double>& input, double num, F lambda_func) {
    if (!input.empty()) {
        for (auto it{input.rbegin()}; it != input.rend(); ++it) {
            num = lambda_func(num, *it);
        }
    }
    return num;
}

}  // namespace list_ops
