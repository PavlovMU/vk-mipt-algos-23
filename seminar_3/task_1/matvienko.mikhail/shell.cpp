#include <iostream>
#include <vector>

void shell_sort(std::vector<int> &arr) {
    int n = arr.size();
    int gap = n/2;
    while (gap > 0) {
        int current_position;
        for (current_position = gap; current_position < n; current_position++) {
            int m_gap = current_position;
            while (m_gap >= gap && arr[m_gap] < arr[m_gap - gap]) {
                int t = arr[m_gap];
                arr[m_gap] = arr[m_gap - gap];
                arr[m_gap - gap] = t;
                m_gap -= gap;
            }
        }

        gap /= 2;
    }
}



int main()
{
    std::vector<int> arr(8);

    for (int i = 0; i < 8; i++)
        std::cin >> arr[i];

    shell_sort(arr);
    for (int i = 0; i < 8; i++)
        std::cout << arr[i] << " ";


    return 0;
}