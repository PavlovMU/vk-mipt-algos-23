#include <iostream>

unsigned int copyTime(unsigned int n, unsigned int x, unsigned int y);

int main(){
    unsigned int n = 0;
    unsigned int x = 0;
    unsigned int y = 0;
    std::cin >> n >> x >> y;
    std::cout << copyTime(n, x, y) << std::endl;

    return 0;
}

unsigned int copyTime(unsigned int n, unsigned int x, unsigned int y){
    unsigned int l = 0;
    unsigned int r = (n - 1) * std::max(x, y);

    while (l + 1 < r){
        unsigned int mid = (r + l) / 2;
        if (mid / x + mid / y < n - 1) l = mid;
        else r = mid;
    }
    return r + std::min(x, y);
}