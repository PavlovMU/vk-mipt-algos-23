import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class SymmetricTreeChecker {

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }

        Queue<TreeNode> levelNodes = new LinkedList<>();
        levelNodes.add(root);

        while (!levelNodes.isEmpty()) {
            int size = levelNodes.size();
            List<Integer> levelValues = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode current = levelNodes.poll();

                if (current != null) {
                    levelValues.add(current.val);
                    levelNodes.add(current.left);
                    levelNodes.add(current.right);
                } else {
                    levelValues.add(null);
                }
            }

            if (!isSymmetricLevel(levelValues)) {
                return false;
            }
        }

        return true;
    }

    private boolean isSymmetricLevel(List<Integer> levelValues) {
        int start = 0;
        int end = levelValues.size() - 1;

        while (start < end) {
            if (!Objects.equals(levelValues.get(start), levelValues.get(end))) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(3);

        SymmetricTreeChecker checker = new SymmetricTreeChecker();
        boolean isSymmetric = checker.isSymmetric(root);
        if (isSymmetric) {
            System.out.println("Дерево симметрично");
        } else {
            System.out.println("Дерево не симметрично");
        }
    }
}
