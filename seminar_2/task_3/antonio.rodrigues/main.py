def BinarySearchSqrt(target):
    l = 0
    r = target

    while l <= r:
        mid = (l + r)/2

        if mid * mid < target:
            l = mid + 1
            continue

        if mid * mid > target:
            r = mid - 1
            continue

        return mid

    return r
