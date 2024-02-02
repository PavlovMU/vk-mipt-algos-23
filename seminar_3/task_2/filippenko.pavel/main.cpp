#include <iostream>
#include <vector>
#include <algorithm>

//? есть ощущение, что не совсем корректно решена задача
int feedAnimals(std::vector<int>* food, std::vector<int>* animals_requests) {
    if ((food->size() == 0) || (animals_requests->size() == 0))
    
    std::sort(food->begin(), food->end());
    std::sort(animals_requests->begin(), animals_requests->end());

    int count = 0;
    for (auto f : food) {
        if ((animals_requests->size() > count) && (f >= (*animals_requests)[count])) {
            count += 1;
        }

        if (count == animals_requests->size()) {
            break
        }
    }

    return cout;
}

int main() {
    
    return 0;
}