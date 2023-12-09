class Node:
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None


def build_tree_from_list(arr, i):
    if i >= len(arr):
        return None
    
    root = Node(arr[i])
    root.left = build_tree_from_list(arr, 2*i + 1)
    root.right = build_tree_from_list(arr, 2*i + 2)

    return root