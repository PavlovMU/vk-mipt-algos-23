#include <iostream>
#include <queue> 

bool isSubsequense(std::string sub_str, std::string str) {
    std::queue<char> quete;
    for(char symbol : sub_str) {
        quete.push(symbol);
    }

    for(char symbol : str) {
        if (quete.front() == symbol) {
            quete.pop();
        }
    }

    return quete.size() == 0;
}

int main() {
    std::string str;
    std::string sub_str;

    std::cin >> sub_str;
    std::cin >> str;

    std::cout << "is " << sub_str << " Subsequense " << str << " " << isSubsequense(sub_str, str) << std::endl;   
}