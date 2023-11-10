#include <iostream>

int sqrt_num(int n) {
  int l = 0, r = n;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid * mid > n) {
      r = mid - 1;
    } else if (mid * mid < n) {
      l = mid + 1;
      ans = mid;
    } else {
      ans = mid;
      break;
    }
  }
  return ans;
}

int main() {
  int num;
  std::cin >> num;
  int res = sqrt_num(num);
  std::cout << res << "\n";
}
