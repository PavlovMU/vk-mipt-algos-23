def findLIS(nums):
    if len(nums) == 0:
        return 0

    if len(nums) == 1:
        return 1

    dp =[1]
    ind = 0

    cur = nums[0]
    i = 1
    while i < len(nums):
        while nums[i + 1] > nums[i]:

            i += 1

        dp[ind] = max(dp[ind - 1], cur)
        ind += 1

    

    return dp[-1]


