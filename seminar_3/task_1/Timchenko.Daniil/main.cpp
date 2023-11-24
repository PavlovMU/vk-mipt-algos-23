#include <vector>

using namespace std;

void shellSort(vector<int>& a) {
    int n = a.size();
    int gap = n/2;
    while (gap > 0) {
        for (int cur_pos = gap; cur_pos < n; ++cur_pos) {
            int m_gap = cur_pos;
            while (m_gap >= gap && a[m_gap] < a[m_gap - gap]) {
                swap(a[m_gap], a[m_gap - gap]);
                m_gap -= gap;
            }
        }
        gap /= 2;
    }
}
