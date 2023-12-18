class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class MinimumDepthFinder {

    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (root.left != null && root.right != null) {
            return 1 + Math.min(minDepth(root.left), minDepth(root.right));
        }

        if (root.left != null) {
            return 1 + minDepth(root.left);
        }

        if (root.right != null) {
            return 1 + minDepth(root.right);
        }

        return 1;

    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(11);
        root.left = new TreeNode(8);
        root.right = new TreeNode(16);
        root.right.left = new TreeNode(6);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(9);
        root.left.right.left = new TreeNode(9);
        root.left.left.left = new TreeNode(7);

        MinimumDepthFinder finder = new MinimumDepthFinder();
        int minDepth = finder.minDepth(root);
        System.out.println("Минимальная глубина дерева: " + minDepth);
    }
}
