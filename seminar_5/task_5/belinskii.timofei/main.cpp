#include <iostream>

int maxProfit(int *arr, const int &size) {
    int profit = 0;
    int min_price = arr[0];
    for (int i = 0; i < size; i++) {
        profit = std::max(profit, arr[i] - min_price);
        min_price = std::min(min_price, arr[i]);
    }
    return profit;
}

int main() {
    int *arr1 = new int[7]{8, 9, 3, 7, 4, 16, 12};
    std::cout << maxProfit(arr1, 7) << std::endl;
    return 0;
}
