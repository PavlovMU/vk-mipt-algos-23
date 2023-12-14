#include <algorithm>

int copy_time(int n, int x, int y) {
  int left = 0;
  int right = (n - 1) * max(x, y);

  while (left + 1 < right) {
    int middle = (right + left) / 2;
    if (middle / x + middle / y < n - 1) {
      left = middle;
    } else {
      right = middle;
    }
  }

  return (right + min(x, y));
}
