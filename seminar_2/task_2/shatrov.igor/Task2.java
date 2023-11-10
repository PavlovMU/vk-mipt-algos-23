import java.util.ArrayDeque;
import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String target = scn.nextLine();

        ArrayDeque<Character> chars = new ArrayDeque<>();

        for (int i = 0; i < target.length(); i++) {
            chars.addLast(target.charAt(i));
        }

        while (!chars.isEmpty()) {
            if (chars.peekLast() != chars.peekFirst()) {
                break;
            }

            chars.removeLast();

            if (!chars.isEmpty()) {
                chars.removeFirst();
            }
        }

        System.out.println(chars.isEmpty());
    }
}
