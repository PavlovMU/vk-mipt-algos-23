#include <iostream>
#include <vector>
#include <algorithm>

//TODO: доделать. Работает не до конца
void shell_sort(std::vector<int>* v) {
    int gap = v->size() / 2; // определяем правую границу

    while (gap > 0) {
        for (int current_position = gap; current_position < v->size(); current_position++) {
            auto m_gap = current_position - gap;
            while ((m_gap > 0) && (*v)[current_position] < (*v)[m_gap]) {
                std::swap((*v)[current_position], (*v)[m_gap]);
                m_gap -= gap;
            }
        }

        gap = gap / 2;
    }
}

int main() {
    std::vector<int> v;
    int N, tmp;
    std::cin >> N;
    for (size_t i = 0; i < N; ++i) {
        std::cin >> tmp;
        v.emplace_back(tmp);
    }

    shell_sort(&v);

    for (auto el : v) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}