#include <iostream>

int copyTime(const int &n, const int &x, const int &y) {
    int l = 0, r = (n - 1) * std::max(x, y), mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (mid / x + mid / y < n - 1) {
            l = mid;
            continue;
        } else {
            r = mid;
            continue;
        }
    }
    return std::min(x, y) + r;
}

int main() {
    std::cout << copyTime(5, 1, 2);
    return 0;
}
