#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int maxMinMultiplication(std::vector<int> &data) {
    if (data.size() < 3)
        return -1;
    
    int min_index = 1;
    int max_index = 2;
    
    for (int i = 1; i < data.size(); i = 2*i + 1)
        min_index =i;

    for (int i = 1; i < data.size(); i = 2*i + 2)
        max_index = i;
    
    return data[min_index] * data[max_index];
}

int main() {


    
    return 0;
}