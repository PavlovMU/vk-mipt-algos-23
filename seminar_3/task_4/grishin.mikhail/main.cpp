#include <unordered_map>
#include <vector>

std::pair<int, int> two_sum(std::vector<int>& data, int target) {
  std::unordered_map<int, int> cache;

  for (int i = 0; i < data.size(); ++i) {
    if (cache.contatins(diff)) {  // only C++ 21 probably
      std::pair<int, int> temp = std::make_pair(i, cache[data[i]]);
      return temp;
    }

    diff = target - data[i];
    cache[diff] = i;
  }
  return -1;
}
