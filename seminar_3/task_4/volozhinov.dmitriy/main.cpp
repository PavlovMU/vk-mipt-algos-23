#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> data, int target) {
    std::unordered_map<int, int> hashMap;
    int diff = 0;
    for (int i = 0; i < data.size(); i++) {
        diff = target - data[i];
        if (hashMap.count(data[i]))
            return std::vector<int> {i, hashMap[data[i]]};
        hashMap[diff] = i;
    }

    return std::vector<int> {};
}

int main() {
    std::vector<int> data{3, 6, 1, 5};
    std::vector<int> a = twoSum(data, 4);
    std::cout << a[0] << a[1] << std::endl;
}