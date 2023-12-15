import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Task1 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        List<Integer> nums = new ArrayList<>();

        while (scn.hasNextInt()) {
            nums.add(scn.nextInt());
        }

        for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
            for (int current_position = gap; current_position < nums.size(); current_position++) {
                int m_gap = current_position;

                while (m_gap >= gap && nums.get(m_gap) < nums.get(m_gap - gap)) {
                    int tmp = nums.get(m_gap);
                    nums.set(m_gap, nums.get(m_gap - gap));
                    nums.set(m_gap - gap, tmp);

                    m_gap -= gap;
                }
            }
        }

        System.out.println(nums.stream().map(String::valueOf).collect(Collectors.joining(" ")));
    }
}