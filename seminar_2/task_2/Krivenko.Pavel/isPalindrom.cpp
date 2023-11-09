#include <iostream>
#include <string>
#include <stack>

std::string isPalindrom(const std::string &s);

int main(){
    std::string s;
    std::cin >> s;
    std::cout << isPalindrom(s);

    return 0;
}

std::string isPalindrom(const std::string &s){
    std::stack<char> stack;
    for (unsigned int i = 0; i < s.size(); ++i){
        stack.push(s[i]);
    }

    for (unsigned int i = 0; i < s.size(); ++i){
        if (s[i] != stack.top()){

            return "not a palindrom\n";
        }
        else stack.pop();
    }

    return "palindrom\n";
}