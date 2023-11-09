#include <iostream>

int binarySearchSqrt (int target) {
    int l = 0, r = target, middle = 0;
    while (l <= r) {
        middle = (l+r)/2;
        if (middle*middle < target) {
            l = middle + 1;
            continue;
        }
        if (middle*middle > target) {
            r = middle - l;
            continue;
        }
        return middle;
    }
    return middle;
}

int main() {
    int t = 0;
    std::cin >> t;
    std::cout << binarySearchSqrt(t) << std::endl;
}