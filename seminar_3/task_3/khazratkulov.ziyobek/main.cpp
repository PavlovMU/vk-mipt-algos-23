#include <iostream>
#include <unordered_set>
#include <string>

std::string extra_etter(std::string s, std::string t) {
    std::unordered_set<char> hash(s.begin(), s.end());
    std::string answer = "";
    for (char k: t) {
        if (hash.find(k) == hash.end()) {
            hash.erase(k);
            answer += k;
        }
    }
    return answer;
}
