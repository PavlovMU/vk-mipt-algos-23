#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int> &prices) {
    int profit = 0;
    int min_price = prices[0];
    for (int currentPriceIndex = 1; currentPriceIndex < prices.size(); currentPriceIndex++) {
        profit = std::max(profit, prices[currentPriceIndex] - min_price);
        min_price = std::min(prices[currentPriceIndex], min_price);
    }
    return profit;
}

int main() {
    std::vector<int> prices = {8, 9, 3, 7, 4, 16, 12};
    std::cout << maxProfit(prices) << std::endl;
}
