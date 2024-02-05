#include <vector>
#include <algorithm>

int maxProfit(std::vector<int> prices){
    int profit = 0;
    int min_price = prices[0];
    for( int currentPriceIndex = 1; currentPriceIndex < prices.size(); currentPriceIndex++){
        profit = std::max(profit, prices[currentPriceIndex] - min_price);
        min_price = std::min (prices[currentPriceIndex], min_price);
    }

    return profit;

}

int main(){
    return 0;
}