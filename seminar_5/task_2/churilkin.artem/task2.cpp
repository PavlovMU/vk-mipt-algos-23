#include<vector>
#include<algorithm>

int findLIS(std::vector<int> nums)
{
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return 1;
    std::vector<int> dp (nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i-1] < nums[i]) { dp[i] = dp[i-1] + 1;}
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main()
{
    return 0;
}