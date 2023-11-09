#include <iostream>
#include <string>
#include <queue>

bool isSubsequence(std::string a, std::string b) {
    std::queue<char> queue = {};
    for (auto elem: a) {
        queue.push(elem);
    }
    for (auto elem:  b) {
        if (queue.back() == elem) {
            queue.pop();
        }
    }
    return queue.empty();
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << isSubsequence(a, b);
}
