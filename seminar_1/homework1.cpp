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

    int target = 0;

    std::cin >> target;

    nums.remove_if([&target](int c) {
            return c == target;
    });

    std::cout << nums.size();
}