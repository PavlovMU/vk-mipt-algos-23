#include <iostream>
#include <unordered_set>
#include <vector>

bool two_sum(std::vector<int>& arr, int target) {
    std::unordered_set<int> hash(arr.begin(), arr.end());
    for (int i : arr) {
        if (hash.find(target - i) != hash.end()) {
            return true;
        }
    }
    return false;
}
