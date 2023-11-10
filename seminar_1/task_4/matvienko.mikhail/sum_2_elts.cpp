#include <iostream>
#include <vector> 

bool func_hasSum(std::vector<int> &arr, int val) {
    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {
        int tmp_sum = arr[i] + arr[j];
        if (tmp_sum < val) 
            i += 1;
        else if (tmp_sum > val) 
            j -= 1;
        else {
            std::cout << i << " and " << j << std::endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int count;
    std::cin >> count;

    if (count < 0)
        return 0; 
    std::vector<int> arr(count);

    //getting sorted array
    for (int i = 0; i < count; i++) {
        int data;
        std::cin >> data;
        arr[i] = data;
    }

    int val;
    std::cout << "Enter val for finding" << std::endl;
    std::cin >> val;

    func_hasSum(arr, val);


    return 0;
}