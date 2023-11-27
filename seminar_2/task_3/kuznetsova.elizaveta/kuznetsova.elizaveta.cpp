#include <iostream>

int binarySearchSqrt(int target) {
    int left = 0;
    int right = target;
    int middle = 0;

    while (left <= right) {
        middle = (left + right) / 2;

        if (middle * middle < target) {
            left = middle + 1;
            continue;
        }

        if (middle * middle > target) {
            right = middle - 1;
            continue;
        }
        return middle;
    }

    return right;
}

int main() {
    int num;
    std::cin >> num;
    std::cout << binarySearchSqrt(num) << std::endl;
}