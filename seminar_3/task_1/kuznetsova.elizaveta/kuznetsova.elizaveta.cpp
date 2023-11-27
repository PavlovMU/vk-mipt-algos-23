#include <iostream>
#include <vector>

std::vector<int> shellSort(std::vector<int> arr) {
    int gap = arr.size() / 2;
    while (gap > 0) {
        for (int current = gap; current < arr.size(); ++current) {
            int mGap = current;
            while (mGap >= gap && arr[mGap] < arr[mGap - gap]) {
                int temp = arr[mGap];
                arr[mGap] = arr[mGap - gap];
                arr[mGap - gap] = temp;
                mGap -= gap;
            }
        }
        gap = gap / 2;
    }
    return arr;
}

int main() {
    int len;    
    std::cin >> len;

    std::vector<int> arr(len);

    for (int i = 0; i < len; ++i) {
        std::cin >> arr[i];
    }

    for (auto elem : arr) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;
    arr = shellSort(arr);

    for (auto elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

}