import java.util.Arrays;

public class FeedAnimals {
    public static void shellSort(int[] arr) {
        int n = arr.length;

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int cur_pos = gap; cur_pos < n; cur_pos++) {
                int m_gap = cur_pos;

                while (m_gap >= gap && arr[m_gap] < arr[m_gap - gap]) {
                    int temp = arr[m_gap - gap];
                    arr[m_gap - gap] = arr[m_gap];
                    arr[m_gap] = temp;
                    m_gap -= gap;
                }
            }
        }
    }

    public static int feedAnimals(int[] animals, int[] food) {
        if (animals.length == 0 || food.length == 0) {
            return 0;
        }

        shellSort(animals);
        shellSort(food);

        int count      = 0;
        int anim_count = animals.length;

        for (int f: food) {
            if (f >= animals[count]) {
                count++;
            }

            if (count >= anim_count) {
                break;
            }
        }

        return count;
        
    }

    public static void main(String[] args) {
        int[] anim = {1, 4, 3, 8};
        int[] food = {8, 2, 3, 2};
        
        System.out.println(feedAnimals(anim, food));
    }

}


