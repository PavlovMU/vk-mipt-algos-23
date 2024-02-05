#include <iostream>
#include <unordered_map>
#include <vector>


std::vector<long> twoSum(std::vector<long> data, long target) {
    std::unordered_map<long, long> map = {};
    for (int i = 0; i < data.size(); ++i) {
        if (map.find(data[i])) {
            return[i, map[data[i]]];
        }
        long diff = target - data[i];
        map[diff] = i;
    }
    return[];
}
