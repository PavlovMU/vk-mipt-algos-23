# Задача 1
# Последовательность n символов из 0 и 1 (без трех подряд 1)

def count_sequences(n):
    if n == 0 or n == 1 or n == 2:
        return n
    
    dp = [1, 2, 4]
    
    for i in range(3, n + 1):
        dp.append(dp[i - 1] + dp[i - 2] + dp[i - 3])
        
    return dp[n]    

#example
print(count_sequences(6))    