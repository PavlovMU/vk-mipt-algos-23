def shell_sort(arr):
    n = len(arr)
    gap = len(arr) // 2
    while gap > 0:

        for current_position in range(gap, n):
            n_gap = current_position

            while n_gap >= gap and arr[n_gap - gap] > arr[n_gap]:
                arr[n_gap - gap], arr[n_gap] = arr[n_gap], arr[n_gap - gap]
                n_gap -= gap

        gap //= 2

    return arr