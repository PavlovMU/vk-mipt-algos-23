#include <iostream>
#include <vector>
#include <algorithm>

long findLIS(std::vector<long> nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return 1;
    }
    std::vector<long> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i - 1] < nums[i]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    long n;
    std::cin >> n;
    std::vector<long> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::cout << findLIS(nums);
}