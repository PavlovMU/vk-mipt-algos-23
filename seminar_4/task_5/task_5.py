# сравнить 2 дерева на идентичность 
# Задача 5

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
def isSameTree(a, b):
    if a == None and b == None:
        return True
    
    if a == None or b == None:
        return False
    
    if a.val != b.val:
        return False
    
    return isSameTree(a.left, b.left) and isSameTree(a.right, b.right)
