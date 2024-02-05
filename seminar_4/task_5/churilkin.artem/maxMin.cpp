#include <vector>
#include <iostream>
#include <cassert>

int maxMinMultiplication(std::vector<int> data) {
    if (data.size() < 2)  return -1;
    
    int min_index = 1;
    int max_index = 2;
    
    for( int i = 1; i < data.size(); i = 2 * i + 1 ) {
        min_index = i;
    }

    for( int i = 1; i < data.size(); i = 2 * i + 2 ) {
        max_index = i;
    }
    int result = data[min_index] * data[max_index];
    return result;
}
