#include <iostream>
#include <unordered_map>
#include <string>

std::string extraLetter(std::string str1, std::string str2) {
    std::unordered_map<char, int> map;
    std::string result;
    for (int i = 0; i < str1.length(); ++i) {
        ++map[str1[i]];
    }
    std::cout << std::endl;

    for (int i = 0; i < str2.length(); ++i) {
        if (map.contains((str2[i]))) {
            --map[str2[i]];
            if (map[str2[i]] == 0) {
                map.erase(str2[i]);
            }
            continue;
        }
        result.push_back(str2[i]);
    }

    for (auto elemMap : map) {
        while (elemMap.second) {
            result.push_back(elemMap.first);
            --elemMap.second;
        }
    }

    return result;
}

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << extraLetter(str1, str2) << std::endl;

}