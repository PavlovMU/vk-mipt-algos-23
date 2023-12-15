import java.util.HashMap;
import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String shortStr = scn.nextLine();
        String longStr = scn.nextLine();

        HashMap<Character, Integer> occurrences = new HashMap<>();

        for (char c : longStr.toCharArray()) {
            int n = occurrences.getOrDefault(c, 0);
            occurrences.put(c, n + 1);
        }

        for (char c : shortStr.toCharArray()) {
            occurrences.computeIfPresent(c, (k, v) -> (v - 1));
        }

        for (var i : occurrences.keySet()) {
            if (occurrences.get(i) > 0) {
                System.out.println(i);
                break;
            }
        }
    }
}
