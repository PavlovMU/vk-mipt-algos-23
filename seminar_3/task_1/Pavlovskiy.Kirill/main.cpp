#include <iostream>

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

int main()
{
    int arr[10] = {2,5,1,0,4,5,6,7,5,37};

    ShellSort(arr, 10);

    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    return 0;
}