#include <iostream>
#include <vector> 
#include <algorithm>


std::vector<int> shellSort(std::vector<int> arr) {
    int gap = arr.size() / 2;
    while (gap > 0) {
        for (int current = gap; current < arr.size(); ++current) {
            int mGap = current;
            while (mGap >= gap && arr[mGap] < arr[mGap - gap]) {
                int temp = arr[mGap];
                arr[mGap] = arr[mGap - gap];
                arr[mGap - gap] = temp;
                mGap -= gap;
            }
        }
        gap = gap / 2;
    }
    return arr;
}

int feedAnimals(std::vector<int> animals, std::vector<int> food) {

    if (animals.size() == 0 || food.size() == 0) {
        return 0;
    }

    animals = shellSort(animals);
    food = shellSort(food);

    int count = 0;
    for (auto elem : food) {
        if (elem >= animals[count]) {
            ++count;
        }
        if (count == animals.size()) {
            break;
        }
    }
    return count;

}



int main() {
    size_t lenAnim;    

    std::cin >> lenAnim;
    std::vector<int> animal(lenAnim);

    for (size_t i = 0; i < lenAnim; ++i) {
        std::cin >> animal[i];
    }

    size_t lenFood;
    std::cin >> lenFood;
    std::vector<int> food(lenFood);
    for (size_t i = 0; i < lenFood; ++i) {
        std::cin >> food[i];
    }

    std::cout << feedAnimals(animal, food) << std::endl;

}