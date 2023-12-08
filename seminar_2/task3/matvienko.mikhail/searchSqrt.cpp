#include <iostream>
#include <vector>

int binarySearch(int target) {

    if (target == 0) return 0;
    if (target == 1) return 1;
    if (target < 0) return -1;

    int l = 0; 
    int r = target;
    int middle = 0;

    while (l <= r)
    {
        middle = (l+r)/2;
    
        if (middle*middle > target) {
            r = middle - 1;
            continue;
        }

        if (middle*middle < target) {
            l = middle + 1;
            continue;
        }

        return middle;
    }

    return r;
    
}


int main() 
{
    //int target;
    //std::cin >> target;

    //std::cout << binarySearch(target) << std::endl;

    std::vector<int> test_data(8);
    test_data = {0, 1, 2, 4, 8, 144, 145, -9};

    for (size_t i = 0; i < test_data.size(); i++) {
        std::cout << "test #" << i << ": number = " << test_data[i] << ", sqrt = " << binarySearch(test_data[i]) << std::endl;
    }

    return 0;
}