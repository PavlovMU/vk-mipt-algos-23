#include <iostream>
#include <vector>
#include <algorithm>

int func(int n) {
    if ((n == 0)||(n == 1)||(n == 2))
        return n;
    std::vector<int> dp = {1, 2, 4};
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << func(n) << std::endl;
}