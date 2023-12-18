class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class SameTreeChecker {

    public boolean isSameTree(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }

        if (a == null || b == null) {
            return false;
        }

        if (a.val != b.val) {
            return false;
        }

        return isSameTree(a.left, b.left) && isSameTree(a.right, b.right);
    }

    public static void main(String[] args) {
        TreeNode rootA = new TreeNode(1);
        rootA.left = new TreeNode(2);
        rootA.right = new TreeNode(3);

        TreeNode rootB = new TreeNode(1);
        rootB.left = new TreeNode(2);
        rootB.right = new TreeNode(3);

        SameTreeChecker checker = new SameTreeChecker();
        boolean result = checker.isSameTree(rootA, rootB);

        if (result) {
            System.out.println("Деревья одинаковы");
        } else {
            System.out.println("Деревья разные");
        }
    }
}