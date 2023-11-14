#include <iostream>
#include <vector>

// функция twoSum возвращает вектор состоящий из различных номеров элеметов в
// заданом векторе (массиве) сумма этих эллементов равна задонному числу в
// случае отсутсвия таких элементов возвращает вектор {0, 0}

std::vector<size_t> twoSum(std::vector<int>& numbers, int target) {
  size_t first = 0;
  size_t last = numbers.size() - 1;
  int result = 0;
  std::vector<size_t> answer = {0, 0};

  for (size_t i = 0; i < numbers.size() - 1; ++i) {
    result = numbers[first] + numbers[last];
    if (result == target) {
      break;
    }
    if (!((result > target) ^ (numbers[last] > 0))) {
      --last;
    } else if (!((result < target) ^ (numbers[last] > 0))) {
      ++first;
    }
  }

  if (result == target) {
    answer[0] = first;
    answer[1] = last;
  }

  return answer;
}

int main() {
  int sum = 0;
  size_t size = 0;
  std::cin >> size;
  std::vector<int> sorted_array;
  for (int i = 0, t = 0; i < size; ++i) {
    std::cin >> t;
    sorted_array.push_back(t);
  }

  std::cin >> sum;

  std::cout << twoSum(sorted_array, sum)[0] << " "
            << twoSum(sorted_array, sum)[1];

  return 0;
}