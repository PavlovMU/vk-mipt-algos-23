#include <iostream>

int binarysearchSqrt(int target) {
    int right  = target;
    int left = 0;

    int middle = -1;

    int square = 0;
    while (left <= right) {
        middle = (left + right) / 2;

        square = middle*middle;
        
        if (square ==  target) {
            return middle;
        }
        
        if (middle*middle > target) {
            right = middle - 1;
            continue;
        }

        if (middle*middle < target) {
            left = middle + 1;
            continue;
        }
    }
    return middle;
}

int main() {
    int target = 0;
    std::cin >> target;
    auto res = binarysearchSqrt(target);
    std::cout << res << std::endl;
    return 0;
}