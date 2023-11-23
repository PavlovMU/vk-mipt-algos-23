def binary_search_sqrt(target):
    l = 0
    r = target

    while l <= r:
        middle = (l + r) // 2
        if middle * middle > target:
            r = middle - 1

        elif middle * middle < target:
            l = middle + 1

        else:
            return middle

    return r
