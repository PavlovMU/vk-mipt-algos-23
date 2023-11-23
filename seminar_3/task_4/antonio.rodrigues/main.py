def twoSum(arr, target):
    hash = set(arr)

    for i in arr:
        if target - i in hash:
            return True

    return False
