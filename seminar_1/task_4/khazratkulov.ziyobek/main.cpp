#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> two_sum(std::vector<int> nums, int target) {
  std::sort(nums.begin(), nums.end());
  int i = 0;
  int j = nums.size() - 1;
  int sum = -1;
  while (i != j) {
    sum = nums[i] + nums[j];
    if (sum > target) {
      --j;
    } else if (sum < target) {
      ++i;
    } else {
      return {i, j};
    }
  }
  return {};
}

