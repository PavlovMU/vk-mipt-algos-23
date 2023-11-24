#include <iostream>
#include <vector>

std::vector<int> shell_sort(std::vector<int> &arr) {
    int n = arr.size();
    int gap = n/2;
    int m_gap = 0;
    while (gap > 0) {
        for (int curr = gap; curr < n; curr++) {
            m_gap = curr;
            while ((m_gap >= gap)&&(arr[m_gap] < arr[m_gap-gap])) {
                std::swap(arr[m_gap], arr[m_gap - gap]);
                m_gap -= gap;
            }
        }
        gap = gap/2;
    }
    return arr;
}


int main() {
    std::vector<int> arr{3, 6, 1, 5};
    arr = shell_sort(arr);
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i];
    std::cout << std::endl;
}