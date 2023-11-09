#include <iostream>

int binarySearchSqrt(int target) {
    int l = 0;
    int r = target;
    int middle = 0;
    while (l < r) {
        middle = (l + r) / 2;
        if (middle * middle < target) {
            l = middle + 1;
            continue;
        }
        if (middle * middle > target) {
            r = middle - 1;
            continue;
        }

        return middle;

    }
    
    return r;
}


int main() {
    int a = binarySearchSqrt(16); 
    if ( a == 4) std::cout << "ok";

    return 0;
}