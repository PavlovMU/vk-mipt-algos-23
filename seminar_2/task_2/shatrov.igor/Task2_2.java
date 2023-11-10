import java.util.Scanner;

public class Task2_2 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String target = scn.nextLine();

        int i = 0, j = target.length() - 1;

        boolean ans = true;

        while (i >= j) {
            if (target.charAt(i) != target.charAt(j)) {
                ans = false;
                break;
            }

            i++;
            j--;
        }

        System.out.println(ans);
    }
}
