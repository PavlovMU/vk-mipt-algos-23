#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr{0, 2, 4, 5, 7, 8};

    int num = 6;

    size_t left =  0;
    size_t right = arr.size();
    int sum = arr[left] + arr[right];

    while ((sum = arr[left] + arr[right]) != num)
    {
        if (sum > num)
            --right;
        else
            ++left;
    }

    std::cout << left << std::endl;
    std::cout << right << std::endl;

    return 1;
}
