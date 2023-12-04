#include <iostream>

int copy_time(int n, int x, int y) {
    int left = 0;
    int right = (n - 1) * std::max(x, y);
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if ((mid / x) + (mid / y) > (n - 1)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right + std::min(x, y);
}

int main() {
    int x, y, n;
    std::cin >> n >> x >> y;
    std::cout << copy_time(n, x, y) << std::endl;
}
