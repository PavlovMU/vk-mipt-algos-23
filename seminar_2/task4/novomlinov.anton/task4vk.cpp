#include <iostream>

int copyTime(int n, int x, int y) {
  int l = 0;
  int r = (n - 1) * std::max(x, y);

  while (l + 1 < r) {
    int mid = (r + l) / 2;
    if (mid / x + mid / y < n - 1) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return r + std::min(x, y);
}

int main() {
}