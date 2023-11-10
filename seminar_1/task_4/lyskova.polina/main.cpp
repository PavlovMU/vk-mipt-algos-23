#include <iostream>
#include <vector>

std::pair<int, int> ind_for_sum(const std::vector<int>& data, int res) {
    int left_ind = 0, right_ind = data.size() - 1;
    while (left_ind < right_ind) {
        int sum = data[left_ind] + data[right_ind];
        if (sum == res) {
            return {left_ind, right_ind};
        } else if (sum > res) {
            right_ind--;
        } else if (sum < res) {
            left_ind++;
        }
    }
    return {-1, -1}; // если решения нет
}
