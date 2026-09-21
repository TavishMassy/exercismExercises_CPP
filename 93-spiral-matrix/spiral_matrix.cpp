#include "spiral_matrix.h"

namespace spiral_matrix {

// TODO: add your solution here
std::vector<std::vector<uint32_t>> spiral_matrix(uint32_t n) {
    if (n == 0) return {};
    // The n x n matrix and initialize with zeros
    std::vector<std::vector<uint32_t>> matrix(n, std::vector<uint32_t>(n, 0));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    uint32_t num = 1;
    while (top <= bottom && left <= right) {
        // 1. Move Left to Right along the top boundary
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++; // Shrink top boundary
        // 2. Move Top to Bottom along the right boundary
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--; // Shrink right boundary
        // 3. Move Right to Left along the bottom boundary
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--; // Shrink bottom boundary
        }   
        // 4. Move Bottom to Top along the left boundary
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++; // Shrink left boundary
        }
    }
    return matrix;
}

}  // namespace spiral_matrix
