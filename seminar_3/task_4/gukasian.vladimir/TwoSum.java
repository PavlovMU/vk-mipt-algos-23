import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public static int[] twoSum(int[] data, int target) {
        Map<Integer, Integer> cache = new HashMap<>();

        for (int i = 0; i < data.length; i++) {
            if (cache.containsKey(data[i])) {
                return new int[]{i, cache.get(data[i])};
            }

            int diff = target - data[i];
            cache.put(diff, i);
        }

        return new int[]{};
    }


    public static void main(String[] args) {
        int[] data = {2, 7, 11, 15};
        int target = 9;

        int[] result = twoSum(data, target);

        if (result.length == 2) {
            System.out.println("Индексы двух чисел: " + result[0] + ", " + result[1]);
        } else {
            System.out.println("Не найдены числа с заданной суммой.");
        }
    }
}

