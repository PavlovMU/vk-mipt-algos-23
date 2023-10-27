import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        MyList lst = new MyList(new Scanner(System.in));

        System.out.println(lst.isLooped());
    }

    private static class MyList {
        Node head;

        public MyList(int n) {
            head = new Node(n);
        }

        public MyList(Scanner scn) {
            head = new Node(scn.nextInt());

            while (scn.hasNextInt()) {
                this.add(scn.nextInt());
            }
        }

        public void add(int n) {
            head.addToHead(n);
        }

        public void print() {
            head.printFromHead();
        }

        public boolean isLooped() {
            if (head.next == null) {
                return false;
            }

            Node slow = head, fast = head.next;

            while (slow != fast) {
                slow = slow.next;

                if (fast.next == null || fast.next.next == null) {
                    return false;
                } else {
                    fast = fast.next.next;
                }
            }

            return true;
        }
    }

    private static class Node {
        int num;
        Node next;

        public Node(int n) {
            num = n;
            next = null;
        }

        public void addToHead(int n) {
            Node current = this;

            while (current.next != null) {
                current = current.next;
            }

            current.next = new Node(n);
        }

        public void printFromHead() {
            Node current = this;

            do {
                System.out.print(current);
                current = current.next;
            } while (current != null);

            System.out.println();
        }

        public String toString() {
            return num + " ";
        }
    }
}
