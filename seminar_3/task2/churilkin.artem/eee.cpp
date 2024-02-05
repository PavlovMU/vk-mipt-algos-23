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



int feedAnimals(std::vector<int> animals, std::vector<int> food){
    if (animals.empty() == 0 or food.empty() == 0) return 0;
    Shell_sort(animals);
    Shell_sort(food);
    int count = 0;
    for (auto f : food){
        if (f >= animals[count]) count += 1;
        if (count == animals.size() ) break;
    }

    return count;


}


int main() {
    std::vector<int> animals = {8, 2, 3, 2};
    std::vector<int> food = {1, 4, 3, 8};
    std::cout << animals[0] << " " << feedAnimals(animals, food);
    return 0;
}