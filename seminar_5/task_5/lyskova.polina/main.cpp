#include <iostream>
#include <vector>

long maxProfit(std::vector<long> prices) {
    long profit = 0;
    long min_price = prices[0];
    for (int i = 0; i < prices.size(); ++i) {
        profit = std::max(profit, prices[i] - min_price);
        min_price = std::min(prices[i], min_price);
    }
    return profit;
}

