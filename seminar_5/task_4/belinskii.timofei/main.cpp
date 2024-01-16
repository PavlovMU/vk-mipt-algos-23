#include <iostream>
#include "algorithm"

int max_length_sequence(const int *arr, int size) {
    if (size == 0 || size == 1) {
        return size;
    }
    int dp[size];
    for (int i = 0; i < size; i++) {
        dp[i] = 1;
    }
    for (int i = 1; i < size; i++) {
        if (arr[i] >= arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    return *std::max_element(dp, dp + size);
}

int main() {
    int N;
    std::cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::cout << max_length_sequence(arr, N);
    return 0;
}
