#include <iostream>


int copyTime(int n,int x,int y) {
    int l = 0, mid = 0;
    int r = (n - 1) * std::max(x, y);

    while (l + 1 < r) {
        mid = (r + l)/2;
        if (mid/x + mid/y < n-1)
            l = mid;
        else
            r = mid;
    }
    return r + std::min(x, y);
}

int main() {
    int n = 0, x = 0, y = 0;
    std::cin >> n >> x >> y;
    std::cout << copyTime(n, x, y) << std::endl;
}