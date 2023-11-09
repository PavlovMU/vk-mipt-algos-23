#include <vector>
#include <utility>

std::pair<int, int> find2IndexesOfSum(std::vector<int>& array, int value) {
    int left = 0;
    int right = array.size() - 1;

    while (left != right) {
        int sum = array[left] + array[right];

        if (sum == value)
            return {left, right};
        
        if (sum < value) left++; else right--;
    }

    return {};
}