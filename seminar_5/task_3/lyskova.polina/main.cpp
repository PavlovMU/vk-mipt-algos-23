#include <iostream>
#include <vector>

void pascal_triangle(long n) {
    std::vector<std::vector<long>> dp;
    for (int i = 0; i < n; ++i) {
        std::vector<long> tmp;
        for (int j = 0; j < i; ++j) {
            tmp.emplace_back(1);
        }
        dp.emplace_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}