#include "largest_series_product.h"
#include <iostream>

namespace largest_series_product {

// TODO: add your solution here
int largest_product(std::string series, size_t span) {
    if (series.empty()) {
        throw std::domain_error(""); 
    }
    if (series.length() < span) {
        throw std::domain_error("");
    }
    int max_product{0};
    int num{1};
    for (size_t i{span}; i <= series.length(); ++i) {
        for (size_t j{span}; j > 0; --j) {
            char c = series[i - j];
            if (c >= '0' && c <= '9') {
                num *= series[i - j] - '0'; 
            } else {
                throw std::domain_error("");
            }
        }
        if (num > max_product) {
            max_product = num;
        }
        num = 1;
    }
    return max_product;
}

}  // namespace largest_series_product
