def maxProfit(prices):
    profit = 0

    min_price = prices[0]

    for x in prices[1:]:
        if min_price > x:
            min_price = x
            continue

        else:
            profit = max(profit, x - min_price)

    return 0
