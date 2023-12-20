#include <iostream>
#include <list>

bool ch_polyndrom_stack(std::string &word) {
    std::list<char> list;
    for (size_t i = 0; i < word.size(); i++) {
        list.push_back(word[i]);
    }
    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] != list.back())
            return false;
        list.pop_back();
    }

    return true;
}

bool ch_polyndrom_2ptr(std::string &word) {
    int i = 0;
    int j = word.length()-1;

    while (i <= j) {
        if (word[i++] != word[j--])
            return false;
    }

    return true;
    
}

int main()
{   
    std::string word;
    std::cout << "Enter word" << std::endl;
    std::cin >> word;

    if (ch_polyndrom_stack(word))
        std::cout << "Word is polyndrom!" << std::endl;
    else 
        std::cout << "Word is not polyndrom!" << std::endl;

    if (ch_polyndrom_2ptr(word))
        std::cout << "Word is polyndrom!" << std::endl;
    else 
        std::cout << "Word is not polyndrom!" << std::endl;

    return 0;
}