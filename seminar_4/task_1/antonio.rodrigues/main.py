class TreeNode:
    def __init__(self, val, left = None, right = None):
        self.left = left
        self.right = right
        self.val = val


def BuildTree(arr, i):
    if i >= len(arr):
        return None

    root = TreeNode(arr[i]) 
    root.left = BuildTree(arr, 2 * i + 1)
    root.right = BuildTree(arr, 2 * i + 2)

    return root

