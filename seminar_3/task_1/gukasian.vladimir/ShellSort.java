import java.util.Arrays;

public class ShellSort {
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

    public static void main(String[] args) {
        int[] array = {12, 34, 54, 2, 3};
        System.out.println("Before: " + Arrays.toString(array));
        shellSort(array);
        System.out.println("After: " + Arrays.toString(array));
    }

}


