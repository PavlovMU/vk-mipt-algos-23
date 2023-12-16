# Задача 4
# Путь с максимальной суммой в бинарном дереве 

def find_max_path_sum(root):
    
    def dfs(node):
        nonlocal max_sum
        if not node:
            return 0, []
        
        left_sum, left_path = dfs(node.left)
        right_sum, right_path = dfs(node.right)
    
        if left_sum > right_sum:
            current_max_path = left_path + [node.val]
        else:
            current_max_path = right_path + [node.val]
    
        current_max_sum = max(left_sum, right_sum) + node.val
    
        if current_max_sum > max_sum:
            max_sum = current_max_sum
            max_path = current_max_path
        
        return current_max_sum, current_max_path 
    
    max_sum = float('-inf')
    max_path = []
    dfs(root)
    return max_sum, max_path 



class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
 
 # example
        
    #    1
    #   / \
    #  2   3
    # / \
    # 4   5
        
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
print(find_max_path_sum(root))