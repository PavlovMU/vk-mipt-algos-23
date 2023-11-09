#include <iostream>
#include <queue>

int main() {
    std::queue<char> q;
    int n = 0, m = 0;
    std::cin >> n >> m;
    char s1[n];
    char s2[m];
    for (int i = 0; i < n; i++) {
        std::cin >> s1[i];
        q.push(s1[i]);
    }
    for (int j = 0; j < m; j++) {
        std::cin >> s2[j];
        if (q.front() == s2[j])
            q.pop();
    }

    std::cout << q.empty() << std::endl;
}