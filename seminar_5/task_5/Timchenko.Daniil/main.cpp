#include <vector>
using namespace std;

int maxProfit(vector<int> prices) {
    int profit = 0;
    int min_price = prices[0];
    for (int cur_price_i = 1; cur_price_i < prices.size(); ++cur_price_i) {
        profit = max(profit, prices[cur_price_i] - min_price);
        min_price = min(prices[cur_price_i], min_price);
    }

    return profit;
}