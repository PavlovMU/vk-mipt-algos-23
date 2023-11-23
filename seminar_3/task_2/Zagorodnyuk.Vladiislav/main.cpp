#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> animals = {1, 4, 3, 8};
    std::vector<int> food = {8, 2, 3, 2};

    std::sort(animals.begin(), animals.end());
    std::sort(food.begin(), food.end());

//     for (int i = 0; i < animals.size(); i++)
//         std::cout << animals[i] << " ";
//
//     std::cout << std::endl;
//
//     for (int i = 0; i < food.size(); i++)
//         std::cout << food[i] << " ";
//
//     std::cout << std::endl;

    int count = 0;

    for (int i = 0; i < food.size(); i++)
    {
        if (food[i] > animals[count])
            count++;

        if (count == animals.size())
            break;
    }

    std::cout << count << std::endl;

    return 0;
}
