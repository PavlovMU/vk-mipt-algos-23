#include <vector>

int feed_animals(std::vector<int>& animals, std::vector<int>& food) {
  if (animals.size() == 0 && food.size() == 0) {
    return 0;
  }

  sort(animals.begin(), animals.end());
  sort(food.begin(), food.end());

  int count = 0;
  for (auto f : food) {
    if (animals.size() > count) {
      if (f >= animals[count]) {
        ++count;
      }

      if (count == animals.size()) {
        break;
      }
    }
  }

  return count;
}
