#include<iostream>
#include<vector>
#include<algorithm>

void Shell_sort(std::vector<int>& vect){
    int gap = vect.size() / 2;
    int m_gap;
    while (gap > 0){
        for (int current_position = gap; current_position < vect.size(); current_position++)
        {
            m_gap = current_position;
            while(m_gap >= gap and vect[m_gap] < vect[m_gap - gap])
            {
                std::swap(vect[m_gap], vect[m_gap-gap]);
                m_gap -= gap;
            }
        }
        gap = gap / 2;
    }

}

int main() {
    std::vector<int> vect = {2, 5, 3, 1, 4, 8, 10};
    Shell_sort(vect);

    for (auto elem : vect){
        std::cout << elem << " ";
    }
    return 0;
}