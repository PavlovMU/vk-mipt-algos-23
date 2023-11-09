if __name__ == "__main__":
    arr = list(map(int, input().split()))
    val = int(input())
    arr.sort()
    i = 0
    j = len(arr) - 1
    while i != j:
        curr_sum = arr[i] + arr[j]
        if curr_sum > val:
            j -= 1
        elif curr_sum < val:
            i += 1
        else:
            print(f"Индексы: {i} и {j}")
            break
