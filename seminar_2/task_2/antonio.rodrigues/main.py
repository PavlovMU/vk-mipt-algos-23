def isPolindrom(a):
    l = [x for x in a]

    for i in a:
        if i != l.pop():
            return False

    return True
