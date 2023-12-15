public class Task5 {
    public static void main(String[] args) {

    }

    public static boolean isSameTree(MyBinaryTreeNode a, MyBinaryTreeNode b) {
        if (a == null && b == null) {
            return true;
        }

        if (a == null || b == null) {
            return false;
        }

        if (a.val != b.val) {
            return false;
        }

        return (isSameTree(a.left, b.left) && isSameTree(a.right, b.right));
    }
}
