Задан массив целых чисел, необходимо вернуть индексы двух элементов, сумма которых равна заданному числу. Набор чисел задан таким образом, что результат может быть только один. Нельзя использовать одно и тоже число дважды.


func find2IndexesOfSum(int[] arr, int target) -> int[] {
    int first = 0
    int last  = arr.size - 1

    while first != last {
        int sum = arr[first]+arr[last]

        if (sum == target) {
            return int[](first, last)
        }
        
        if (sum < target) {
            first = first + 1
        } else if (sum > target) {
            last = last - 1
        }
    }

    return int[]()
}
