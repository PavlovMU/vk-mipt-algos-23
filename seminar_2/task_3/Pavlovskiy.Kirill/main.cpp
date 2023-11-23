#include <iostream>

int SearchSqrt(int target);

int SearchSqrt(int target)
{
    int left = 0, right = target;

    int middle = 0;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (middle * middle < target)
        {
            left = middle + 1;

            continue;
        }

        if (middle * middle > target)
        {
            right = middle - 1;

            continue;
        }

        return middle;
    }

    return right;
}

int main()
{
    for (int i = 0; i < 20; i++)
        std::cout << i << " : " << SearchSqrt(i) << std::endl;

    return 0;
}