import java.util.ArrayList;
import java.util.Scanner;

public class Task4 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int wantedSum = scn.nextInt();

        ArrayList<Integer> nums = new ArrayList<>();      // sorted array

        while (scn.hasNextInt()) {
            nums.add(scn.nextInt());
        }

        int i = 0, j = nums.size() - 1;
        while (i != j) {
            int sum = nums.get(i) + nums.get(j);

            if (sum == wantedSum) {
                System.out.println(i + " " + j);
                return;
            }

            if (sum < wantedSum) {
                i++;
            } else {
                j--;
            }
        }

        System.out.println("No such indices");
    }
}
