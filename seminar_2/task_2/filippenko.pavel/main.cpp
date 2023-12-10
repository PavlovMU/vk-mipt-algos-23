#include <iostream>

bool isPalindrom(char* str, size_t sz) {
    size_t i = 0;
    size_t j = sz-1;

    while(i <= j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char* a = "abba";
    size_t size_a = 4;
    char* b = "hgf";
    size_t size_b = 3;

    if (isPalindrom(a, size_a)) {
        std::cout << "True" << std::endl;
    }

    if (isPalindrom(b, size_b)) {
        std::cout << "True" << std::endl;
    }
}