#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> data, int target) {
    std::unordered_map<int, int> map;
    std::vector<int> array;
    for (int i = 0; i < data.size(); ++i) {
        int diff = target - data[i];
        if (map.contains(data[i])) {
            array.push_back(i);
            array.push_back(map[diff]);
            return array;
        }
        map[diff] = i;
    }
    return array;
}

int main() {
    int len, target;
    std::cin >> len;
    std::vector<int> arr(len);

    for (int i = 0; i < len; ++i) {
        std::cin >> arr[i]; 
    }
    std::cin >> target;
    std::vector<int> answer = twoSum(arr, target);

    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << " ";
    }
    std::cout << std::endl;
}