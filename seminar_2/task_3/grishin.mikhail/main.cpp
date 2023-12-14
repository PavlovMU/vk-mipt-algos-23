int binary_search_sqrt(int target) {
  int left = 0;
  int right = target;

  while (left <= right) {
    int middle = (l + r) / 2;
    if (middle * middle > target) {
      right = middle - 1;
      continue;
    }
    if (middle * middle < target) {
      right = middle + 1;
      continue;
    }
    return middle;
  }
  return right;
}
