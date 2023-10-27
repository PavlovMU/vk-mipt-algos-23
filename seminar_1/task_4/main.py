if __name__ == "__main__":
    arr = list(map(int, input("Массив: ").split()))
    val = int(input("Сумма: "))
    arr = sorted(arr)
    i = 0
    j = len(arr) - 1
    tmp = arr[i] + arr[j]
    while tmp != val:
        if (i < len(arr) - 1) and (j > 0):
            if val > tmp:
                j -= 1
                tmp = arr[i] + arr[j]
            elif val < tmp:
                i += 1
                tmp = arr[i] + arr[j]
            else:
                print("Всё ок")
                break
        else:
            print("Не ок")
