def two_ptr(array, cnt):
    i = 0
    k = len(array)
    while i != k:

        if (array[i] + array[k]) == cnt:
            return i, k

        elif array[i] + array[k] > cnt:
            i += 1
        else:
            k -= 1

    return False
