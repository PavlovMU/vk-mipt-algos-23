def is_two_sum_array(arr: list, s: int) -> tuple[int, int]:
	# l is sorted
	l = 0, r = len(arr) - 1
	while r - l >= 0:
		if arr[l] + arr[r] > s:
			r -= 1
		elif arr[l] + arr[r] < s:
			l += 1
		else:
			return l, r
	return -1, -1


