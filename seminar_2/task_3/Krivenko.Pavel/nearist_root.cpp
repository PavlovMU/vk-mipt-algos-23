#include <iostream>
#include <vector>

unsigned int nearist_root(unsigned int target);

int main(){
    //-----------------------TESTS-----------------------
    std::cout << nearist_root(25) << std::endl;
    std::cout << nearist_root(5) << std::endl;
    std::cout << nearist_root(16) << std::endl;
    std::cout << nearist_root(6) << std::endl;
    std::cout << nearist_root(10) << std::endl;

    return 0;
}

unsigned int nearist_root(unsigned int target){
    std::vector<unsigned int> nums(target + 1);
    for (unsigned int i = 0; i < target + 1; ++i){
        nums[i] = i;
    }

    unsigned int l = 0;
    unsigned int r = target;

    for (unsigned int i = 0; i < target + 1; ++i){
        unsigned int middle = (l + r) / 2;

        if (nums[middle] * nums[middle] <= target) l = middle;

        else r = middle;

    }

    return nums[l];
}