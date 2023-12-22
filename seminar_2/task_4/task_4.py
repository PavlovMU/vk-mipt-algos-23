# очень простая задача (последняя)

def copy_time(n, x, y):
    
    l = 0 # самый удобный случай
    r = (n - 1) * max(x, y) # рассматриваем худший случай реализации

    while l + 1 < r:
        
        mid = (l + r) // 2
        
        if (mid // x) + (mid // y) < (n - 1):
            l = mid
        else:
            r = mid
            
        print(l, r)
        
    return r + min(x, y)    
            
    
print(copy_time(8, 1, 2))    
