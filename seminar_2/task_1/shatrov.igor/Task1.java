import java.util.ArrayDeque;
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String target = scn.nextLine(), small = scn.nextLine();

        ArrayDeque<Character> chars = new ArrayDeque<>();

        for (int i = 0; i < small.length(); i++) {
            chars.addLast(small.charAt(i));
        }

        for (int i = 0; i < target.length(); i++) {
            if (chars.isEmpty()) {
                break;
            }

            if (chars.peekFirst() == target.charAt(i)) {
                chars.removeFirst();
            }
        }

        System.out.println(chars.isEmpty());
    }
}