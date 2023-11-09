#include <iostream>
#include <stack>
#include <string>

bool isPalindrome(std::string s) {
    std::stack<char> Stack;
    for (int i = 0; i < s.length(); i++)
        Stack.push(s[i]);
    for (int j = 0; j < s.length(); j++) {
        if (Stack.top() != s[j])
            return 0;
        Stack.pop();
    }
    return 1;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::string s1;
    for (int i = 0; i < n; i++) {
        std::cin >> s1[i];
    }

    std::cout << isPalindrome(s1) << std::endl;
}