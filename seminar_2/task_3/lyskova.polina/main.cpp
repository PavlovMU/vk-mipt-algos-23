#include <iostream>


long long findSqrt(long long num) {
    long long left = 0;
    long long right = num;
    while (left <= right) {
        long long middle = (left + right) / 2;
        if (middle * middle < num) {
            left = middle + 1;
            continue;
        }
        if (middle * middle > num) {
            right = middle - 1;
            continue;
        }
        return middle;
    }
    return right;
}

int main() {
    long long s;
    std::cin >> s;
    std::cout << findSqrt(s);
}