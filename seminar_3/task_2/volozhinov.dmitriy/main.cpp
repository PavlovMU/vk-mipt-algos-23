#include <iostream>
#include <vector>

std::vector<int> sort(std::vector<int> &arr) {
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

int feedAnimals(std::vector<int> &animals, std::vector<int> &food) {
    if ((animals.size() == 0)&&(food.size() == 0))
        return 0;
    
    sort(animals);
    sort(food);

    int count = 0;
    for (int i = 0; i < food.size(); i++) {
        if (food[i] >= animals[count])
            count++;
        if (count == animals.size())
            break;
    }
    return count;
}

int main() {
    std::vector<int> animals{3, 7, 1, 5};
    std::vector<int> food{3, 6, 1, 5};

    std::cout << feedAnimals(animals, food) << std::endl;
}