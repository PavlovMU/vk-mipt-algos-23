#include <iostream>
#include <vector>
#include <algorithm>

int feed(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    int cnt = 0;

    for (int i : arr1) {
        int k = 0;
        for (int g = k; g < arr2.size(); ++g) {
            if (arr2[g] == i) {
                k = g + 1;
                cnt++;
                break;
            }
            if (arr2[g] > i) {
                k = 1;
                break;
            }
        }
    }

    return cnt;
}
