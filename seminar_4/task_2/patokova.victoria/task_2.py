class Node:
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None


def is_symmetrical_bfs(root):
    nodes = [root]

    while nodes:
        
        children = []

        for cur_node in nodes:
            if cur_node.left:
                children.append(cur_node.left)

            if cur_node.right:
                children.append(cur_node.right)

        left = 0
        right = len(children)
        while left <= right:
            if children[left] != children[right]:
                return False
            left += 1
            right -= 1

    return True