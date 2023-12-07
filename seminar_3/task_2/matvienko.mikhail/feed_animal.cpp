#include <iostream>
#include <vector>
#include <algorithm>

int feed_animal(std::vector<int> animal, std::vector<int> food) {

    if (animal.size() == 0 || food.size() == 0)
        return 0;

    //sorting arrays
    std::sort(animal.begin(), animal.end());
    std::sort(  food.begin(),   food.end());

    int count = 0;

    for (auto f : food) {
        if (f >= animal[count]) {
            count++;
        }

        if (count == (int)animal.size()) 
            break;
    }

    return count;   
    
}



int main()
{
    std::vector<int> animal, food;

    int get;
    std::cin >> get;
    while (get != 0) {
        animal.push_back(get);
        std::cin >> get;
    }

    std::cin >> get;
    while (get != 0) {
        food.push_back(get);
        std::cin >> get;
    }

    std::cout << feed_animal(animal, food) << std::endl;

    return 0;
}