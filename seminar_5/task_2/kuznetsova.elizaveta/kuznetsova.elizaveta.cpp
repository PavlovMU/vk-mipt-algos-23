#include <iostream> 
#include <vector>
#include <algorithm>

int findLIS(std::vector<int> nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return 1;
    }

    std::vector<int> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] < nums[i]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
  
    int max = dp[0];
    for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;

}

int main() {
    size_t len;

    std::cin >> len;
    std::vector<int> arr(len);

    for (int i = 0; i < len; ++i) {
        std::cin >> arr[i];
    } 
    std::cout << findLIS(arr) << std::endl;

}