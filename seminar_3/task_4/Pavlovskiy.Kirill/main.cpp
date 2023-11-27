#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> Sum(int* arr, int size, int target);

std::vector<int> Sum(int* arr, int size, int target)
{
    std::unordered_map<int, int> map{};

    std::vector<int> nums{};
 
    int diff = 0;

    for (int i = 0; i < size; i++)
    {
        if (map.count(arr[i]))
        {
            nums.push_back(i);

            nums.push_back(arr[i]);
        }

        diff = target - arr[i];

        map[diff] = i;
    }

    return nums;
}

int main()
{
    int arr[8] = {4,9,6,7,3,1,8,5};

    std::vector<int> nums = Sum(arr, 8, 7);

    std::cout << "7 = " << nums[0] << " + " << nums[1] << std::endl;
 
    return 0;
}