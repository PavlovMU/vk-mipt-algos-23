import javax.swing.*;
import java.awt.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class BinaryTreeBuilder {
    private TreeNode root;

    public TreeNode buildTree(int[] array) {
        if (array == null || array.length == 0) {
            return null;
        }

        root = buildTreeFromArray(array, 0);
        return root;
    }

    private TreeNode buildTreeFromArray(int[] array, int index) {
        if (index < array.length) {
            TreeNode node = new TreeNode(array[index]);
            node.left = buildTreeFromArray(array, 2 * index + 1);
            node.right = buildTreeFromArray(array, 2 * index + 2);
            return node;
        }
        return null;
    }

    public void visualizeTree() {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                drawTree(g, root, getWidth() / 2, 30, getWidth() / 4);
            }
        };
        frame.setContentPane(panel);
        frame.setVisible(true);
    }

    private void drawTree(Graphics g, TreeNode node, int x, int y, int xOffset) {
        if (node != null) {
            int nodeRadius = 20;

            g.setColor(Color.black);
            g.fillOval(x, y, nodeRadius * 2, nodeRadius * 2);
            g.setColor(Color.white);
            g.drawString(String.valueOf(node.val), x + nodeRadius - 5, y + nodeRadius + 5);

            if (node.left != null) {
                g.setColor(Color.black);
                g.drawLine(x + nodeRadius, y + nodeRadius * 2, x - xOffset + nodeRadius * 2, y + 60);
                drawTree(g, node.left, x - xOffset, y + 60, xOffset / 2);
            }

            if (node.right != null) {
                g.setColor(Color.black);
                g.drawLine(x + nodeRadius, y + nodeRadius * 2, x + xOffset + nodeRadius * 2, y + 60);
                drawTree(g, node.right, x + xOffset, y + 60, xOffset / 2);
            }
        }
    }

    public static void main(String[] args) {
        BinaryTreeBuilder builder = new BinaryTreeBuilder();
        int[] array = {1, 2, 3, 4, 5, 6, 7};

        builder.buildTree(array);
        builder.visualizeTree();
    }
}