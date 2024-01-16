#include <iostream>

void twoSum(int *arr, int n, int target) {
    int cache[target + 1];
    for (int i = 0; i < target + 1; i++) {
        cache[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (cache[arr[i]] != -1) {
            std::cout << arr[i] << ' ' << cache[arr[i]];
            return;
        }
        cache[target - arr[i]] = arr[i];
    }
}

int main() {
    int arr[]{1, 2, 2, 2, 4, 5, 6};
    int target = 7;
    twoSum(arr, 7, 7);
}
