#include <iostream>

int count_sequences(const int &N) {
    if (N == 0) {
        return 1;
    } else if (N == 1 || N == 2) {
        return 2 * N;
    }
    int dp[N + 1];
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i < N+1; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    return dp[N];
}

int main() {
    int N;
    std::cin >> N;
    std::cout << count_sequences(N);
    return 0;
}
