#include <iostream>

int gap(const int &k) {
    return 2 * k - 1;
}

void shell_sort(int *arr, const int &n) {
    int k = (n + 1) / 2;
    int g = gap(k);
    while (g > 0) {
        for (int cur = g; cur < n; cur++) {
            int cur1 = cur;
            while (cur1 >= g && arr[cur1] <= arr[cur1 - g]) {
                std::swap(arr[cur1], arr[cur1 - g]);
                cur1 -= g;
            }
        }
        g = gap(--k);
    }
}

int main() {
    int arr[]{0, 5, 3, 4, 1, 0, 0, 2, 1};
    shell_sort(arr, 9);
    for (auto i: arr) {
        std::cout << i << ' ';
    }
    return 0;
}
