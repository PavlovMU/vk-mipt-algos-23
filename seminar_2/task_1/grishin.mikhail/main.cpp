#include <queue>

bool is_subsequence(std::vector<int>& a, std::vector<int>& b) {
  std::queue<int> q;
  for (auto i : a) {
    q.push(i);
  }
  for (auto i : b) {
    auto temp = q.front();
    if (temp == i) {
      q.pop();
    }
  }

  return q.empty();
}
