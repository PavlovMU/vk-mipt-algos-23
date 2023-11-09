def ind(nums, n):
    l_index = 0
    r_index = len(nums) - 1
    while l_index < r_index:
        sum_data = nums[l_index] + nums[r_index]
        if sum_data == n:
            return l_index, r_index
        elif sum_data < n:
            l_index += 1
        elif sum_data > n:
            r_index += 1

    return 'NO indexes'

