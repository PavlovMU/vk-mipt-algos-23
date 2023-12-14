#include <vector>

void shell_sort(std::vector<int>& arr) {
  int n = arr.size();
  int gap = n / 2;

  while (gap > 0) {
    for (int curr_pos = gap; curr_pos < n; ++curr_pos) {
      int m_gap = curr_pos;

      while (m_gap >= gap && arr[m_gap] < arr[m_gap - gap]) {
        swap(arr[m_gap], arr[m_gap - gap]);
        m_gap -= gap;
      }
    }
    gap /= 2;
  }
}

