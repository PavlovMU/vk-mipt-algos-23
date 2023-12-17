
def isSameTree(a, b):
    if a == None and b == None:
        return True  

    if a is not None or b is not None:
        return False

    if a.data != b.data:
        return False

    return isSameTree(a.left, b.left) and isSameTree(a.right, b.right)
