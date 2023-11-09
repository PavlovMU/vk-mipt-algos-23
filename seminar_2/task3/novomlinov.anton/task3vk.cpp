#include <iostream>

int binarySearchSqrt(int target) {
  int l = 0;
  int r = target;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid * mid < target) {
      l = mid + 1;
      continue;
    }
    if (mid * mid > target) {
      r = mid - 1;
      continue;
    }
    return mid;
  }
  return r;
}

int main() {
}