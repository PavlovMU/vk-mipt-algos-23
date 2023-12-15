import java.util.Scanner;

public class Task4 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt(), speed1 = scn.nextInt(), speed2 = scn.nextInt();

        int ans = Math.min(speed1, speed2);
        n--;

        int left = -1, right = n * Math.max(speed1, speed2) + 1;

        while (left + 1 != right) {
            int mid = left + (right - left) / 2;

            int copiesPrinted = mid / speed1 + mid / speed2;

            if (copiesPrinted <= n) {
                left = mid;
            } else {
                right = mid;
            }
        }

        System.out.println(ans + left);
    }
}
