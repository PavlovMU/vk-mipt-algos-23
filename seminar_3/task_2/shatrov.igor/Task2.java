import java.util.Arrays;

public class Task2 {
    public static void main(String[] args) {
        int[] needs = new int[] {1, 4, 3, 8};
        int[] meals = new int[] {8, 2, 3, 1};

        System.out.println(feed(needs, meals));
    }

    public static int feed(int[] needs, int[] meals) {
        if (needs.length == 0 || meals.length == 0) {
            return 0;
        }

        Arrays.sort(needs);
        Arrays.sort(meals);

        int animalsFed = 0;
        for (int meal : meals) {
            if (animalsFed < needs.length && meal >= needs[animalsFed]) {
                animalsFed++;
            }

            if (animalsFed == needs.length) {
                break;
            }
        }

        return animalsFed;
    }
}
