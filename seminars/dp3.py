# треугольник Паскаля
def foo(n: list):
    dp = [[1], [1, 1]]
    if n == 1 or n == 2:
        return dp
    
    #TODO: добавить еще рекурентную функцию
    #TODO: можно инициализировать изначально dp нужным количеством единиц
    for i in range(2, n+1):
        new_raw = []
        new_raw.append(1)
        for j in range(1, len(dp[i-1])):
            new_raw.append(dp[i-1][j] + dp[i-1][j-1])
        new_raw.append(1)
        dp.append(new_raw)
    return dp


def main():
    n = 5
    dp = foo(n)
    for row in dp:
        print(' '.join(map(str, row)))
        # print(row)

if __name__ == '__main__':
    main()