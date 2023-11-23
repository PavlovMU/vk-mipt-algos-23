// find a closest number int to sqrt of of a number

#include <iostream>

int bin_search_sqrt(int target)
{
    int l = 0;
    int r = target;

    while (l <= r)
    {
        int middle = (l+r)/2;
        int middle2 = middle * middle;

        if (middle2 < target)
        {
            l = middle + 1;;
            continue;
        }

        if (middle2 > target)
        {
            r = middle - 1;
            continue;
        }

        return middle;
    }

    return r;
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::cout << bin_search_sqrt(n) << "\n";

    return 0;
}
