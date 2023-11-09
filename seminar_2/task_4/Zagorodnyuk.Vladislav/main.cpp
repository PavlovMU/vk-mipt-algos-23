#include <iostream>

int copy_time(int n, int x, int y)
{
    int l = 0;
    int r = (n-1)*std::max(x,y);

    while (l+1<r)
    {
        int middle = (l+r)/2;

        if (middle/x + middle/y < n-1)
            l = middle;

        else
            r = middle;
    }

    return r + std::min(x,y);
}

int main()
{
    int n = 0;
    int y = 0;
    int x = 0;

    std::cin >> n >> x >> y;
    std::cout << copy_time(n, x, y) << "\n";

    return 0;
}
