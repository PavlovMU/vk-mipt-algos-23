#include <iostream>
#include "string"
#include "deque"
#include "stack"

bool isPalindrome_deque(const std::string &word) {
    std::deque<char> dq1;
    for (auto el: word) {
        dq1.push_front(el);
    }
    while (!dq1.empty()) {
        if (dq1.front() == dq1.back()) {
            dq1.pop_front();
            if (dq1.empty())
                return true;
            dq1.pop_back();
        } else
            return false;
    }
    return true;
}

bool isPalindrome_stack(const std::string &word) {
    std::stack<char> st1;
    for (auto el: word) {
        st1.push(el);
    }
    for (auto el: word) {
        if (st1.top() != el)
            return false;
        st1.pop();
    }
    return true;
}

bool isPalindrome_2ptr(const std::string &word) {
    int l = 0, r = word.size() - 1;
    while (l < r) {
        if (word[l] != word[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    std::cout << isPalindrome_deque("abcba") << '\n';
    std::cout << isPalindrome_stack("abab") << '\n';
    std::cout << isPalindrome_2ptr("aa") << '\n';
    return 0;
}
