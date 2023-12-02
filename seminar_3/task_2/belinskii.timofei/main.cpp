#include <iostream>
#include <bits/stdc++.h>

int gap(const int &k) {
    return 2 * k - 1;
}

void shell_sort(int *arr, const int &n) {
    int k = (n + 1) / 2;
    int g = gap(k);
    while (g > 0) {
        for (int cur = g; cur < n; cur++) {
            int cur1 = cur;
            while (cur1 >= g && arr[cur1] <= arr[cur1 - g]) {
                std::swap(arr[cur1], arr[cur1 - g]);
                cur1 -= g;
            }
        }
        g = gap(--k);
    }
}

int main() {
    int M;
    std::cout << "Еда: ";
    std::cin >> M;
    int food[M];
    for (int i = 0; i < M; i++) {
        std::cin >> food[i];
    }
    int N;
    std::cout << "Животные: ";
    std::cin >> N;
    int animals[N];
    for (int i = 0; i < N; i++) {
        std::cin >> animals[i];
    }
    shell_sort(animals, N);
    shell_sort(food, M);
    if (N == 0)
        std::cout << 0;
    else {
        int count = 0;
        for (int i = 0; i < std::min(N, M); i++) {
            if (animals[i] <= food[i]) {
                count += 1;
            }
        }
        std::cout << count;
    }
    return 0;
}
