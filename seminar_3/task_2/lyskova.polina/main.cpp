#include <iostream>
#include <vector>

long feedAnimals(std::vector<long> animals, std::vector<long> food) {
    if (animals.size() == 0 || food.size() == 0) {
        return 0;
    }
    std::sort(animals);
    std::sort(food);
    long count = 0;
    for (int i = 0; i < food.size(); i++) {
        if (food[i] >= animals[count]) {
            count += 1;
        }
        if (count == animals.size()) {
            break;
        }
    }
    return count;
}S
