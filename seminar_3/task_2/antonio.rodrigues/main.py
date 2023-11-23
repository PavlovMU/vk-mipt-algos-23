def korm(arr1, arr2):
    sorted(arr1)
    sorted(arr2)
    cnt = 0

    for i in arr1:
        k = 0
        for g in range(k, len(arr2)):
            if arr2[g] == i:
                k = g + 1
                cnt += 1
                break
            if arr2[g] > i:
                k = 1
                break 

    return cnt

