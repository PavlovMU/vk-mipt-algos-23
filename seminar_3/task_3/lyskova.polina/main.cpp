#include <iostream>
#include <string>
#include <unordered_map>

char extraLetter(std::string a, std::string b) {
    std::unordered_map<char, int> hash = {};
    for (int i = 0; i < a.size(); ++i) {
        hash[a[i]]++;
    }
    for (int i = 0; i < b.size(); ++i) {
        if (hash.find(b[i])->second != 0) {
            hash[a[i]]--;
            if (hash[a[i]] == 0) {
                hash.erase(b[i]);
                continue;
            }
            continue;
        }
        return b[i];
    }
    return '\0';
}