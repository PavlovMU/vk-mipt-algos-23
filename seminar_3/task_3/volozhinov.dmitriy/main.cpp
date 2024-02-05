#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

char extraLetter(std::string a, std::string b) {
    std::unordered_map<char, int> hashMapA;
    for (int i = 0; i < a.length(); i++)
        hashMapA[a[i]]++;
    
    for (int j = 0; j < a.length(); j++) {
        if (hashMapA.count(b[j])) {
            hashMapA[b[j]]--;
            if (hashMapA[b[j]] == 0) {
                hashMapA.erase(b[j]);
                continue;
            }
            continue;
        }
        return b[j];
    }   
    return '0';
}

int main() {
    std::string a = "ABC";
    std::string b = "ABCD";
    std::cout << extraLetter(a, b) << std::endl;
}