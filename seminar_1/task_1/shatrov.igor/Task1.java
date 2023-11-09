import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int target = scn.nextInt();

        MyList lst = new MyList(scn);

        lst.delAll(target);

        lst.print();
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

        public void delAll(int n) {
            Node dummy = new Node(0);
            dummy.next = head;

            Node prev = dummy, current = head;

            while (current != null) {
                if (current.num == n) {
                    prev.next = current.next;
                } else {
                    prev = current;
                }

                current = current.next;
            }

            head = dummy.next;
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