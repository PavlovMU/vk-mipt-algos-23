#include <iostream> 
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int> prices) {
    int profit = 0;
    int minPrice = prices[0];

    for (size_t current = 1; current < prices.size(); ++current) {
        profit = std::max(profit, prices[current] - minPrice);
        minPrice = std::min(prices[current], minPrice);
    }

    return profit;
}


int main() {
    size_t len;

    std::cin >> len;
    std::vector<int> arr(len);

    for (size_t i = 0; i < len; ++i) {
        std::cin >> arr[i];
    } 
    std::cout << maxProfit(arr) << std::endl;
}