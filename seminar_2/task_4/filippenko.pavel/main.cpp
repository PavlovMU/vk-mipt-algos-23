#include <iostream>

namespace MyTask
{
    int copyTime(int n, int x, int y) {
    int left = 0;
    int right = (n-1) * std::max(x, y);

    while (left + 1 < right) {
        int mid = (right + left) / 2;
        if (mid /x + mid / y < n-1) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right + std::min(x, y);
}
} // namespace MyTask

int main() {
    int copy_number = 0;
    int x = 0;
    int y = 0;
    std::cin >> copy_number;
    std::cin >> x;
    std::cin >> y;

    std::cout << MyTask::copyTime(copy_number, x, y) << std::endl;
    return 0;
}