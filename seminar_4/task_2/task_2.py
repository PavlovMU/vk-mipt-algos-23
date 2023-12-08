# Понять симметричное ли дерево 
# Задача 2

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_symmetric(root):
    if not root:
        return True
    return is_mirror(root.left, root.right)

def is_mirror(left, right):
    if not left and not right:
        return True
    if not left or not right:
        return False
    return (left.val == right.val) and is_mirror(left.left, right.right) and is_mirror(left.right, right.left)


