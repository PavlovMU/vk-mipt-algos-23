#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSumElts(std::vector<int> array, int target) {

    std::unordered_map<int, int> hash_t;

    for (int i = 0; i < (int)array.size(); i++) {
        auto hit = hash_t.find(array[i]);
        if (hit == hash_t.end())
            hash_t.emplace(array[i], 1);
        else    
            (hit->second)++;
    }

    for (int elt : array) {
        int find_elt = target - elt;

        auto hit = hash_t.find(find_elt);
        if (hit == hash_t.end())
            continue;
        if (find_elt == elt) {
            if (hit->second > 1)
                return {elt, hit->first};
            else 
                return {};
        } 

        return {elt, hit->first};
    }

    return {};
}

int main()
{
    std::vector<int> array;
    int lenght = 0;
    std::cin >> lenght;
    
    int data;
    for (int i = 0; i < lenght; i++) {
        std::cin >> data;
        array.push_back(data);
    }

    int target;
    std::cin >> target;

    std::vector<int> ans = twoSumElts(array, target);
    for (int elt : ans)
        std::cout << elt << " ";
    std::cout << std::endl;


    return 0;
}