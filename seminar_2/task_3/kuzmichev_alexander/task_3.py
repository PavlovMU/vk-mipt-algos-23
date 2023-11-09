n = int(input())
l = 1
r = n
flag = True
while l < r - 1:
    middle = (l + r) // 2
    if middle**2 > n:
        r = middle
    elif middle**2 < n:
        l = middle
    else:
        print(middle)
        flag = False
        break
if flag:
    if n - l**2 < r**2 - n:
        print(l)
    else:
        print(r)
