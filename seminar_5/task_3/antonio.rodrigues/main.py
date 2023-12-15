def Pascale(n):
    dp = [[1], [1, 1]]

    if n < 2:
        return dp

    for row in range(2, n):
        dp.append([1])
        for k in range(len(dp[row - 1]) - 1):
            dp[row].append(dp[row - 1][k] + dp[row - 1][k + 1])

        dp[row].append(1)

    return dp

