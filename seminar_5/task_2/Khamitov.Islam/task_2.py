# Задача 2
# Найти наибольшую  возрастающую подпоследовательность

def findLIS(nums):
    
    if len(nums) == 0:
        return 0
    if len(nums) == 1:
        return 1
    
    dp = [1] * len(nums)
    for i in range(1, len(nums)):
        if nums[i-1]<nums[i]:
            dp[i] = dp[i - 1] + 1
            
    return max(dp)        

# example
a = [1,2,3,5,6,8,9,45,12,2,3,4,5,6,7,8,9,91,25]
print(findLIS(a))