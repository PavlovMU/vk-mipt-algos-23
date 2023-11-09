n = int(input())
x = int(input())
y = int(input())

l = 0
r = n * max(x, y)

while l + 1 < r:
    mid = (l + r) // 2
    if mid // x + mid // y < n - 1:
        l = mid
    else:
        r = mid
print(r + min(x, y))
