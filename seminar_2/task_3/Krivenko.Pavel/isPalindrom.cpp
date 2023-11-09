#include <iostream>
#include <string>
#include <stack>

bool isPalindrom(const std::string &s);

int main(){
    std::string s = "ABBA";
    std::cout << isPalindrom(s);

    return 0;
}

bool isPalindrom(const std::string &s){
    std::stack<char> stack;
    for (unsigned int i = 0; i < s.size(); ++i){
        stack.push(s[i]);
    }

    for (unsigned int i = 0; i < s.size(); ++i){
        if (s[i] != stack.top()){

            return false;
        }
        else stack.pop();
    }

    return true;
}