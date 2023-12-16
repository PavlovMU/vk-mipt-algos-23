# Задача 5 
# Максимальная выгода . Есть массив чисел ,каждое - акция. Как наиболее выгодно купить и продать?

def maxProfit(prices):
    profit = 0
    min_price = prices[0]
    
    for cur_pr_index in range(len(prices)):
        profit = max(profit, prices[cur_pr_index] - min_price)
        min_price = min(prices[cur_pr_index], min_price)
        
    return profit

# example
prices = [2,15 ,14,3,6,9,48,15,1,2,12]
print(maxProfit(prices))