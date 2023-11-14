# в этой реализации предполагается, что такие индексы существуют и все данные введены корректно

def find_indexes(arr, val):
    left = 0
    right = len(arr) - 1

    while left < right:
        if arr[left] + arr[right] > val:
            right -= 1
        elif arr[left] + arr[right] < val:
            left += 1
        else:
            return left, right



arr = [1, 2, 3, 4, 5, 7, 11, 12]

val = int(input())

index1, index2 = find_indexes(arr, val)
print(index1, index2)