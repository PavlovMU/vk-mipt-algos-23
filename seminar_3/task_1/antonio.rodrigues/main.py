def shell_sort(arr):
    n = len(arr)
    gap = n / 2
    while gap > 0:
        current_pos = gap
        for current_pos in range(n):
            m_gap = current_pos
            while m_gap >= gap and arr[m_gap] < arr[m_gap - gap]:
                arr[m_gap], arr[m_gap - gap] = arr[m_gap], arr[m_gap]

            m_gap -= gap
        gap = gap / 2
          
    return arr
