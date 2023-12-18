public class MinMaxMul {
    public int maxMinMultiplication(int[] data) {
        if (data.length < 3) {
            return -1;
        }

        int minIndex = findMinIndex(data, 1);
        int maxIndex = findMaxIndex(data, 2);

        int result = data[minIndex] * data[maxIndex];
        return result;
    }

    private int findMinIndex(int[] data, int startIndex) {
        int minIndex = startIndex;

        for (int i = startIndex; i < data.length; i = 2 * i + 1) {
            if (data[i] < data[minIndex]) {
                minIndex = i;
            }
        }

        return minIndex;
    }

    private int findMaxIndex(int[] data, int startIndex) {
        int maxIndex = startIndex;

        for (int i = startIndex; i < data.length; i = 2 * i + 2) {
            if (data[i] > data[maxIndex]) {
                maxIndex = i;
            }
        }

        return maxIndex;
    }
    public static void main(String[] args) {
        int[] array = {16, 12, 18, 11, 15, 17, 21};
        MinMaxMul calculator = new MinMaxMul();
        int result = calculator.maxMinMultiplication(array);
        System.out.println("Произведение минимального и максимального значений: " + result);
    }
}
