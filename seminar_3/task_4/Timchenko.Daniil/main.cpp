#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;


pair<int, int> twoSum(vector<int> a, int target) {
    unordered_map<int, int> cache;
    for (int i=0; i<a.size(); ++i) {
        if (cache.contains(a[i]))
            return {i, cache[a[i]]};
        cache[target - a[i]] = i;
    }
    return {0, 0};
}