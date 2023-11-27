#include <iostream>
#include <algorithm>

int ShellSort(int* arr, const int size);

int ShellSort(int* arr, const int size)
{
    int gap = size / 2;

    while (gap > 0)
    {   
        for (int cur_pos = gap; cur_pos < size; cur_pos++)
        {
            int m_gap = cur_pos;

            while (arr[m_gap] < arr[m_gap - gap] && m_gap >= gap)
            {
                std::swap(arr[m_gap - gap], arr[m_gap]);

                m_gap -= gap;
            }

        }

        gap /= 2;
    }

    return 0;
}

int Animals(int* animals, int* food, int size_an, int size_food);

int Animals(int* animals, int* food, int size_an, int size_food)
{
    ShellSort(animals, size_an);

    // for (int i = 0; i < size_an; i++)
    //     std::cout << animals[i] << " ";

    // std::cout << std::endl;

    ShellSort(food, size_food);

    // for (int i = 0; i < size_food; i++)
    //     std::cout << food[i] << " ";

    // std::cout << std::endl;

    int count = 0;

    int size = std::min(size_an, size_food);

    for (int i = size; i != 0; i--)
    {
        if (food[i] >= animals[i])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int food[5] = {1,4,3,8,5};

    int animals[6] = {8,2,3,2,5,4};

    std::cout << Animals(animals, food, 6, 5) << std::endl;

    return 0;
}