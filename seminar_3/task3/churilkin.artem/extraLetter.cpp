#include <iostream>
#include <unordered_map>

char extraLetter(std::string a, std::string b){
    std::unordered_map<char, int> m;
    for (char c : a){
        m[c]++;
    }
    for (char c: b){
        m[c]--;
    }
    for (auto it : m){
        if(it.second != 0) return it.first;
    }
    return ' ';
}

int main() {
    std::string a = "abc";
    std::string b = "ab";
    std::cout << extraLetter(a, b);
    return 0;
}
