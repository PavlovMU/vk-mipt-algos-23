#include <iostream>

int binarySearchSqrt(const int &n) {
    int l = 0, r = n, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mid * mid < n) {
            l = mid + 1;
            continue;
        }
        if (n < mid * mid) {
            r = mid - 1;
            continue;
        }
    }
    return mid;
}

int main() {
    std::cout << binarySearchSqrt(10);
    return 0;
}
