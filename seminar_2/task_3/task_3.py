
# третья задачка
# найти корнеь числа (ближайшее целое)

def sqrt_nearest(target):
    l = 0
    r = target 
    
    while l <= r:
        
        mid = (l + r) // 2
        
        if mid * mid == target:
            return mid
        elif mid * mid > target:
            r = mid - 1
        else:
            l = mid + 1
        
        print(l, r)
    return mid

print(sqrt_nearest(63))

