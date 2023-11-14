#include <iostream>
#include <stack>


bool isPalindrome(std::string str) {
    std::stack<char> stack; 

    for (char symbol : str) {
        stack.push(symbol);
    }
    for (char symbol : str) {
        if (symbol != stack.top()) {            
            return false;
        }
        stack.pop();
    }
    
    return true;
}


int main() {
    std::string str;

    std::cin >> str;

    std::cout << isPalindrome(str) << std::endl;
}