#include <iostream>
#include <vector>

// [1,2,4,5,6]  8

//-------------------------------------------------------------------------------//

int HasSum(std::vector<int> arr, int sum, int* index1, int* index2);

//-------------------------------------------------------------------------------//

int HasSum(std::vector<int> arr, int sum, int* index1, int* index2)
{
    if ((arr[*index1] + arr[*index1 + 1]) > sum || (arr[*index2] + arr[*index2 - 1]) < sum)
    {
        *index1 = 0;

        *index2 = 0;

        return 0;
    }

    while (arr[*index1] + arr[*index2] != sum)
    {
        if ((arr[*index1] + arr[*index2]) < sum)
            *index1 += 1;

        else if ((arr[*index1] + arr[*index2]) > sum)
            *index2 -= 1;

        if (arr[*index1] + arr[*index2] != sum && (*index2 - *index1) == 0)
        {
            *index1 = 0;

            *index2 = 0;

            return 0;
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------//

int main()
{
    int size = 0;

    std::cout << "Enter the size of array" << std::endl;

    std::cin >> size;

    std::vector<int> arr(size);

    std::cout << "Enter the elements of array" << std::endl;

    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    int index1 = 0, index2 = size - 1;

    // std::cout << "Enter the sum" << std::endl;

    // int sum = 0;

    // std::cin >> sum;

    for (int i = 0; i < 20; i++)
    {
        HasSum(arr, i, &index1, &index2);
        std::cout << "For sum " << i << " " << index1 << " " << index2 << std::endl;

        index1 = 0;

        index2 = size - 1;
    }

    // HasSum(arr, sum, &index1, &index2);

    // std::cout << index1 << " " << index2 << std::endl;

    return 0;
}

//-------------------------------------------------------------------------------//