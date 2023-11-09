#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int>& SearchBySum(std::vector<int> arr, int val) {
  int left = 0;
  int right = arr.size() - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == val)
      return {left, right};
    else if (sum < val) {
      ++left;
    } else {
      --right;
    }
  }
  return {};
}