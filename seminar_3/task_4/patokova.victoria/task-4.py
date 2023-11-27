def two_sum(arr, target):
    dict = { arr[i]: i for i in range(len(arr)) }
    
    for i in range(len(arr)):
        if target - arr[i] in dict.keys():
            return i, dict.get(target - arr[i])
        
    return None
