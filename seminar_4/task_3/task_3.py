# 3 задача
# Поиск минимальной глубины бинарного дерева 

def minDepth(root):
    if not root:
        return 0
    
    if root.left != None and root.right != None:
        return 1 + min(minDepth(root.left), minDepth(root.right))
    
    if root.left != None:
        return 1 + minDepth(root.left)
    
    if root.right != None:
        return 1 + minDepth(root.right)
    
