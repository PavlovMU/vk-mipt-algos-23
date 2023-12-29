#include <iostream>
#include <vector>
#include <algorithm>

void out(std::vector<int> &data) {
    for (int i = 0 ; i < data.size(); i++)
        std::cout << data[i] << " ";
}

void func(int n) {
    std::vector<std::vector<int>> dp;
    for (int i = 1; i <= n; i++) {
//        std::vector<int> tmp(i);
        for (int j = 1; j <= i; j++)
            dp[i-1][j-1] = 1;
//        dp[i-1] = tmp;
    }

    for (int row = 1; row < n; row++) {
        for (int col = 1; col < row; col++)
            dp[row][col] = dp[row-1][col-1] + dp[row-1][col];
    }
    for (int k = 0; k < dp.size(); k++) {
        out(dp[k]);
        std::cout << std::endl;
    }
}


int main() {
    int n = 0;
    std::cin >> n;
    func(n);
}