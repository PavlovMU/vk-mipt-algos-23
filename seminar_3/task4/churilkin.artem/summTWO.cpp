#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> data, int target){
    std::unordered_map<int, int> cache;
    for (int i = 0; i < data.size(); ++i){
        if (cache.find(data[i]) != cache.end()) {
            return {i, cache[data[i]]};
        }
        int diff = target - data[i];
        cache[diff] = i;
    }
    return {};
}

int main(){
    std::cout <<  twoSum({1, 2, 3, 5, 7, 8, 10}, 9)[0] << " " << twoSum({1, 2, 3, 5, 7, 8, 10}, 9)[1] << std::endl;
    return 0;
}
