def swap(arr: list, idx_A: int, idx_B: int) -> None:
    tmp = arr[idx_A]
    arr[idx_A] = arr[idx_B]
    arr[idx_B] = tmp

def shell_sort(arr: list, gap: int) -> None:
    current_position = gap
    while (current_position < len(arr)):
        if (arr[current_position] < arr[current_position - gap]):
            factor = 1
            while ((current_position - factor*gap >= 0) and (arr[current_position] < arr[current_position - factor*gap])):
                factor += 1
            swap(arr, current_position, current_position - (factor-1)*gap)
        current_position += 1
    if gap < 2:
        return
    else:
        shell_sort(arr, gap=int(gap/2))

def main():
    # arr = [4, 7, 3, 90, 12, 2, 7, 9]
    # arr = [1]
    arr = [2, 2, 2, 2, 2, 2, 2, 2, 0]
    shell_sort(arr, gap=int(len(arr) / 2))
    print(arr)

if __name__ == '__main__':
    main()