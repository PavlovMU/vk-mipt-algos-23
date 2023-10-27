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

    std::list<int> evenNums;

    nums.remove_if([&evenNums](int c) {
            if (c % 2 == 0) {
                evenNums.push_back(c);
                return true;
            }

            return false;
    });

    for (auto i = evenNums.rbegin(); i != evenNums.rend(); ++i) {
        nums.push_front(*i);
    }

    for (int n : nums) {
        std::cout << n << " ";
    }
}