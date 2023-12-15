import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Task3 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        List<Integer> arr = Arrays.stream(scn.nextLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        MyBinaryTreeNode root = Task1.buildTree(arr, 0);

        System.out.println(minDepth(root));
    }

    public static int minDepth(MyBinaryTreeNode root) throws IllegalArgumentException {
        if (root == null) {
            return 0;
        }

        if (root.left != null && root.right != null) {
            return 1 + Math.min(minDepth(root.left), minDepth(root.right));
        }

        if (root.left != null) {
            return minDepth(root.left);
        }

        if (root.right != null) {
            return minDepth(root.right);
        }

        throw new IllegalArgumentException("How did we get here?");
    }
}
