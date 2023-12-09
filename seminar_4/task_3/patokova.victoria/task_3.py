class Node:
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None


def min_depth(root):
    if not root:
        return 0
    
    if root.left is not None and root.right is not None:
        return 1 + min(min_depth(root.left), min_depth(root.right))
    
    if root.left is not None:
        return 1 + min_depth(root.left)
    
    if root.right is not None:
        return 1 + min_depth(root.right)
    
    if root.left is None and root.right is None:
        return 0