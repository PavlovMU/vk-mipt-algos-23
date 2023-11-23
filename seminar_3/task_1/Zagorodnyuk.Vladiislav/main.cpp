#include <iostream>
#include <vector>

void shell_sort(std::vector<int>& arr)
{
    int n = arr.size();
    int gap = n / 2;

    while (gap > 0)
    {
        for (int current_position = gap; current_position < n; current_position++)
        {
            int m_gap = current_position;
            while (m_gap >= gap && arr[m_gap] < arr[m_gap - gap])
            {
                std::swap(arr[m_gap], arr[m_gap - gap]);
                m_gap -= gap;
            }
        }
    }
}

int main()
{
    std::vector<int> arr = {1, -6, 14, 9, 0, 133, 12, 12, -4};

    shell_sort(arr);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    return 0;
}
