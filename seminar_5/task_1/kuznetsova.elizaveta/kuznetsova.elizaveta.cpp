#include <iostream> 
#include <vector>

int func(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    std::vector<int> dp = {1, 2 , 4};

    for (int i = 3; i <= n; ++i) {
        dp.push_back(dp[i - 1] + dp[i -2] + dp[i - 3]);
    }
    return dp[n];
}

int main() {

    int number;
    std::cin >> number;
    std::cout << func(number) << std::endl;
}