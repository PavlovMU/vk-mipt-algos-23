#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string word;
    std::cin >> word;
    std::stack<char> char_stack;
    int length = word.length();
    int mid = length / 2;
    for (int i = 0; i < mid; ++i) {
        char_stack.push(word[i]);
    }
    if (length % 2 != 0) {
        ++mid;
    }
    for (int i = mid; i < length; ++i) {
        if (word[i] != char_stack.top()) {
            std::cout << "no" << std::endl;
        }
    }
    std::cout << "yes" << std::endl;
}
