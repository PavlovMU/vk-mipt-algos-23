#include <iostream>
#include <vector>

long count_sequences(long n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    std::vector<long> dp = {1, 2, 4};
    for (int i = 3; i <= n; i++) {
        // working magic
        dp.emplace_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
    }
    return dp[n];
}
