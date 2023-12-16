# Задача 1: восстановить бинарное дерево из массива

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.data = val
        self.left = left
        self.right = right
        
        
def buildTree(arr, i):
    
    if i >= len(arr):
        return None
    
    root = TreeNode(arr[i]) 
    root.left = buildTree(arr, 2 * i + 1) 
    root.right = buildTree(arr, 2 * i + 2)
    
    return root

arr = [8, 9, 7, 6, 1, 52, 3, 4, 55, 6, 17]
buildTree(arr, 0)