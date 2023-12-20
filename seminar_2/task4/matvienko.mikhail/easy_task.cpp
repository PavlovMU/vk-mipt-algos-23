#include <iostream>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int min(int x, int y) {
    return (x > y) ? y : x;
}

int time_task(int x, int y, int n) {
    int l = 0, r = (n-1) * max(x, y);

    while (l+1 < r) {
        int middle = (l+r)/2;

        if (middle/x + middle/y < n-1) {
            l = middle;
        } else r = middle;
    }

    return r + min(x,y);
}


int main() 
{
    int x = 0, y = 0, n = 0;

    std::cin >> x;
    std::cin >> y;
    std::cin >> n;

    std::cout << "Time: " << time_task(x, y, n) << std::endl;

    return 0;
}