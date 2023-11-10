def sqrt_bin_search(num):
    l, r = 0, num

    while(l <= r):
        middle = (l + r) // 2
        sqr_middle = middle * middle

        if(sqr_middle < num):
            l = middle + 1
            continue

        if(sqr_middle > num):
            r = middle - 1
            continue

        return middle
    
    return r

num = 17
print(f"Approximate value from below for the number sqrt({num}) is {sqrt_bin_search(num)}.")
