#include <iostream>
#include "string"

char extraLetter(const std::string &a, const std::string &b) {
    int hashMap[256];
    for (int i = 0; i < 256; i++) {
        hashMap[i] = 0;
    }
    for (unsigned char letter: b) {
        hashMap[int(letter)]++;
    }
    for (unsigned char letter: a) {
        hashMap[int(letter)]--;
    }
    for (int i = 0; i < 256; i++) {
        if (hashMap[i] > 0) {
            return char(i);
        }
    }
    return '\n';
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << extraLetter(a, b);
    return 0;
}
