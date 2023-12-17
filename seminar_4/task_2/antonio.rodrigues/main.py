def IsSymmetric(TreeNode):
    parents = []

    parents.append(TreeNode)

    while len(parents) == 0:
        new_parents = []
        for parent in parents:
            if parent.left:
                new_parents.append(parent.left)
            if parent.right:
                new_parents.append(parent.right)

        j = len(new_parents) - 1

        for i in range((len(new_parents) // 2)):
            if new_parents[i].data != new_parents[j].data:
                return False

            j -= 1

        parents = new_parents

    return True


                


