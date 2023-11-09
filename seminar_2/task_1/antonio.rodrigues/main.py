def isSubstr(a, b):
    q = [x for x in a] 

    for el in b:
        if q[-1] ==  el:
            q.pop()

    return len(q) == 0
