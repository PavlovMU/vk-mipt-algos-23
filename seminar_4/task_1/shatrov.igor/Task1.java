import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Task1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        List<Integer> arr = Arrays.stream(scn.nextLine().split(" "))
                                  .map(Integer::parseInt)
                                  .collect(Collectors.toList());

        MyBinaryTreeNode root = buildTree(arr, 0);

        printChildren(root);
    }

    public static MyBinaryTreeNode buildTree(List<Integer> arr, int i) {
        if (i >= arr.size()) {
            return null;
        }

        MyBinaryTreeNode root = new MyBinaryTreeNode(arr.get(i));
        root.left = buildTree(arr, 2 * i + 1);
        root.right = buildTree(arr, 2 * i + 2);

        return root;
    }

    private static void printChildren(MyBinaryTreeNode root) {
        System.out.print(root.val + ": ");
        System.out.print((root.left == null ? "null" : root.left.val) + " ");
        System.out.println(root.right == null ? "null" : root.right.val);

        if (root.left != null) {
            printChildren(root.left);
        }

        if (root.right != null) {
            printChildren(root.right);
        }
    }
}