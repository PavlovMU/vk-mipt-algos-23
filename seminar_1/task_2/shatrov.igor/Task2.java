import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {
        MyList lst = new MyList(new Scanner(System.in));

        lst.reverse();

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

        public void reverse() {
            Node prev = null;
            Node current = head;

            while (current != null) {
                Node tmp = current.next;
                current.next = prev;
                prev = current;
                current = tmp;
            }

            head = prev;
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
