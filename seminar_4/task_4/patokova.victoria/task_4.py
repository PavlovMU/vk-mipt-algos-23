class Node:
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None


def min_max_mult(data):
    if len(data) < 3:
        return -1
    
    min_index = 1
    max_index = 2

    while (min_index * 2 + 1) < len(data):
        min_index = min_index * 2 + 1

    while (max_index * 2 + 2) < len(data):
        max_index = max_index * 2 + 1

    return data[min_index] * data[max_index]
    