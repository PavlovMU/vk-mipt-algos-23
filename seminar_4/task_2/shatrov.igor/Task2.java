import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
                                                   //8 9 11 7 16 3 1
public class Task2 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        List<Integer> arr = Arrays.stream(scn.nextLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        MyBinaryTreeNode root = Task1.buildTree(arr, 0);

        System.out.println(isSymmetric(root));
    }

    public static boolean isSymmetric(MyBinaryTreeNode root) {
        if (root == null) {
            return true;
        }

        ArrayList<Integer> lst = new ArrayList<>();

        search(root, lst);

        for (int i = 0; i < lst.size(); i++) {
            if (!lst.get(i).equals(lst.get(lst.size() - i - 1))) {
                return false;
            }
        }

        return true;
    }

    public static void search(MyBinaryTreeNode node, ArrayList<Integer> lst) {
        if (node == null) {
            return;
        }

        search(node.left, lst);
        lst.add(node.val);
        search(node.right, lst);
    }
}
