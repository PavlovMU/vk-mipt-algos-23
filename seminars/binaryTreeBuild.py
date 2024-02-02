class TreeNode:
    def __init__(self, val = 0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# left child = 2i+1
# right child = 2i+2

# восстановление дерева из массива
def binaryTreeBuild(arr: list, idx: int) -> None:
    if (idx >= len(arr)):
        return None
    
    root = TreeNode(arr[idx])
    left_child = binaryTreeBuild(arr, 2*idx+1)
    root.left = left_child
    right_child = binaryTreeBuild(arr, 2*idx+2)
    root.right = right_child
    return root

# проверить дерево на симметричность
# обход в ширину + 2 указателя
# или обход в глубину + стек
def isSemetric(root: TreeNode) -> bool:
    nodes = []
    # считаем, что дерево полное
    while len(nodes) != 0:
        queue = []
        for current in nodes:
            # заполняем очередь
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        
        # проверяем уровень на симметричность
        nodes = queue

def LNR(root: TreeNode, arr: list):
    if root.left != None:
        LNR(root.left, arr)
    if root.right != None:
        LNR(root.right, arr)
    arr.append(root.val)

# найти минимальную ветку
def minDepth(top: TreeNode) -> int:
    ans_left = 0
    ans_right = 0
    if top.left == None:
        return 1
    else:
        ans_left = minDepth(top.left) + 1

    if top.right == None:
        return 1
    else:
        ans_right = minDepth(top.right) + 1
    return min(ans_right, ans_left)

# произведение максимального и минимального элемента в бинарном дереве поиска
def min_max_multiplication(arr: list) -> int:
    if (len(arr) < 3):
        return None

    min_idx = 1
    max_idx = 2
    ...

# сравнить 2 дерева
# идти обходом в ширину и сравнивать слои 
# либо можем обходить в глубину сразу по 2м деревьям
def isEqual(a: TreeNode, b: TreeNode):
    if a == None and b == None:
        return True
    if a.val != b.val:
        return False
    return isEqual(a.left, b.left) and (a.right, b.right)

def main():
    N = int(input())
    arr = list(map(int, input().split(" ")))

if __name__ == '__main__':
    main()