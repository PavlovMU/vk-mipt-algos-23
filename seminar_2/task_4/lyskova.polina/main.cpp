#include <iostream>

// одна копия на старте уже есть
long long printTime(long long n, long long x, long long y) {
    long long left = 0;
    long long right = (n - 1) * std::max(x, y);
    while (left + 1 < right) {
        long long middle = (right + left) / 2;
        if (middle / x + middle / y < n - 1) {
            left = middle;
            continue;
        } else {
            right = middle;
            continue;
        }
    }
    return right + std::min(x, y);
}

int main() {
    long long time_first, time_second, required_num;
    std::cin >> required_num >> time_first >> time_second;
    std::cout << printTime(required_num, time_first, time_second);
}
