#include <iostream>
#include <string>
#include <stack>

bool isPalindrome(const std::string& s) {
    std::stack<char> stack = {};
    for (auto elem: s) {
        stack.push(elem);
    }
    for (auto elem:  s) {
        if (stack.top() != elem) {
            return false;
        }
        stack.pop();
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << isPalindrome(s);
}
