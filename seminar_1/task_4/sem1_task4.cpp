#include <iostream>
#include <vector>

void sumIndex(std::vector<int>& arr, int sum, int* answer) {
    int beginning = 0;
    int end = arr.size()-1;
    int prevSum = arr[beginning] + arr[end];
    while (beginning != end) {
        if (prevSum == sum) {
            answer[0] = beginning;
            answer[1] = end;
            return;
        }
        if (prevSum < sum)
            beginning++;
        if (prevSum > sum)
            end--;
        prevSum = arr[beginning] + arr[end];
    }
    answer[0] = -1;
    answer[1] = -1;
}

int main() {
    std::vector<int> sortedArr = {1, 4, 8, 9, 9, 10};
    std::vector<int> sortedArr2 = {1, 1, 8, 9, 9, 10};
    int sum = 12;

    int* answer = new int[2];
    sumIndex(sortedArr, sum, answer);
    if (answer[0] == -1)
        std::cout << "No such elements" << std::endl;
    else
        std::cout << "Indicies are: " << answer[0] << ", " << answer[1] << std::endl;

    int* answer2 = new int[2];
    sumIndex(sortedArr2, sum, answer2);
    if (answer2[0] == -1)
        std::cout << "No such elements" << std::endl;
    else
        std::cout << "Indicies are: " << answer2[0] << ", " << answer2[1] << std::endl;
}