#include <iostream>
#include "queue"
#include "string"

bool isSubsequence_pt1(const std::string &a, const std::string &b) {
    std::queue<char> q1;
    for (auto el: a) {
        q1.push(el);
    }
    int i = 0;
    while (!q1.empty()) {
        if (q1.front() == b[i])
            i++;
        if (i == b.size())
            return true;
        q1.pop();
    }
    if (i < b.size())
        return false;
    else
        return true;
}

bool isSubsequence_pt2(const std::string &a, const std::string &b) {
    int j = 0;
    for (char el: a) {
        if (el == b[j])
            j++;
    }
    if (j < b.size())
        return false;
    else
        return true;
}

int main() {
    std::cout << isSubsequence_pt1("abfdsdf", "ff") << '\n';
    std::cout << isSubsequence_pt2("abfdsdf", "bsa");
    return 0;
}
