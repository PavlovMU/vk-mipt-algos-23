import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int target = scn.nextInt();
        
        int left = -1, right = target + 1;

        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            
            if (mid * mid > target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        System.out.println(left);
    }
}
