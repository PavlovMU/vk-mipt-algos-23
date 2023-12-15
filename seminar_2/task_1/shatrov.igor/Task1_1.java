import java.util.Scanner;

public class Task1_1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String target = scn.nextLine(), small = scn.nextLine();

        int j = 0;
        for (int i = 0; i < target.length() && j < small.length(); i++) {
            if (target.charAt(i) == small.charAt(j)) {
                j++;
            }
        }

        System.out.println(j == small.length());
    }
}