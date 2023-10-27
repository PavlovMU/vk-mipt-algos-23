#include <iostream>
#include <list>
#include <algorithm>

int main() {
    int size = 0;

    std::cin >> size;

    std::list<int> nums;

    for (int i = 0; i < size; i++) {
        int num = 0;

        std::cin >> num;

        nums.push_back(num);
    }


    int initSize = nums.size();

    nums.remove_if([](int c) {
        return c == 0;
    });

    int zerosToAdd = initSize - nums.size();

    for (int i = 0; i < zerosToAdd; i++) {
        nums.push_back(0);
    }

    for (int num : nums) {
        std::cout << num << " ";
    }
}