#include <iostream>
#include <vector>

std::vector<double> shell_sort(std::vector<double> arr) {
    long n = arr.size();
    long gap = n / 2;
    while (gap > 0) {
        for (curr_pos = gap; curr_pos < n; curr_pos++) {
            long m_gap = curr_pos;
            while (m_gap >= gap && arr[m_gap] < arr[m_gap - gap]) {
                std::swap(arr[m_gap], arr[m_gap - gap]);
                m_gap -= gap;
            }
        }
        gap = gap / 2;
    }
    return arr;
}
