#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator>

char extraLetter(std::string a, std::string b) {

    std::unordered_map<char, int> hash_t;

    for (char letter : a) {
        auto hit = hash_t.find(letter);
        if (hit == hash_t.end())
            hash_t.emplace(letter, 1);
        else 
            (hit->second)++;
    }

    for (char letter : b) {
        auto hit = hash_t.find(letter);
        if (hit == hash_t.end())
            return letter;
        (hit->second)--;
        if (hit->second == -1)
            return letter;
    }

    return '\0';
}


int main()
{
    std::string a, b;

    std::cin >> a >> b;
    std::cout << extraLetter(a, b) << std::endl;

    return 0;
}