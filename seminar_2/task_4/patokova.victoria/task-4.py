def copy_time(n, x, y):
    l = 0
    r = (n - 1) * max(x, y)

    while l + 1 < r:
        mid = (l + r) // 2

        if (mid // x) + (mid // y) > (n - 1):
            r = mid

        else:
            l = mid

    return r + min(x, y)
