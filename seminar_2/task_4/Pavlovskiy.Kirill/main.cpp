#include <iostream>

int SearchFunction(int x_speed, int y_speed, int num);

int SearchFunction(int x_speed, int y_speed, int num)
{
    int left = 0, right = (num - 1) * std::max(x_speed, y_speed);

    int middle = 0;

    while (left + 1 < right)
    {
        middle = (left + right) / 2;

        if (middle / x_speed + middle / y_speed < num - 1)
            left = middle;

        else
            right = middle;
    }

    return right + std::min(x_speed, y_speed);
}

int main()
{
    int num = 0, x = 0, y = 0;

    std::cin >> num >> x >> y;

    std::cout << SearchFunction(x, y, num) << std::endl;

    return 0;
}