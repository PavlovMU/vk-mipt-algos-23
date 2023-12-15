import java.util.HashMap;

public class Task4 {
    public static void main(String[] args) {
        int[] data = new int[] {1, 2, 3, 4, 5};

        int[] ans = twoSum(data, 9);

        if (ans != null) {
            for (int num : ans) {
                System.out.println(num);
            }
        }
    }

    public static int[] twoSum(int[] data, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < data.length; i++) {
            int diff = target - data[i];

            if (map.containsKey(diff)) {
                return new int[] {i, map.get(diff)};
            }

            map.put(data[i], i);
        }

        return null;
    }
}
