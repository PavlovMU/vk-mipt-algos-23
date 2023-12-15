import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Task4 {
    public static void main(String[] args) {

    }

    public static int minMaxMult(List<Integer> data) {
        if (data.size() < 3) {
            return -1;
        }

        int minIndex = 1, maxIndex = 2;

        for (int i = 1; i < data.size(); i = 2 * i + 1) {
            minIndex = i;
        }

        for (int i = 1; i < data.size(); i = 2 * i + 2) {
            minIndex = i;
        }

        return data.get(minIndex) * data.get(maxIndex);
    }
}
