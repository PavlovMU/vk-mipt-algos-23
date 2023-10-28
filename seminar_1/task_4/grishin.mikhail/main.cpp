#include <vector>
#include <utility>

std::pair<int, int> find_sum(int needed_sum, std::vector &vec) {
  int small = 0;
  int big = vec.size() - 1;
  
  int sum = vec[small] + vec[big];
  while (sum != needed_sum) {
    if (sum < needed_sum) ++small;
    else --big;
  }
  std::pair<int, int> ans = std::make_pair(vec[small], vec[big]);
  return ans;
}

