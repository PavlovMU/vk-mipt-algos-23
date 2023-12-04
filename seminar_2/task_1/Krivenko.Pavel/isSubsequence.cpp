#include <iostream>
#include <queue>
#include <string>

std::string isSubsequence(const std::string &a, const std::string &b);

int main(){
    //-----------------------TESTS-----------------------
    std::string a1 = "aba";
    std::string b1 = "ab";
    std::cout << isSubsequence(a1, b1);

    std::string a2 = "ab";
    std::string b2 = "aba";
    std::cout << isSubsequence(a2, b2);

    std::string a3 = "ab";
    std::string b3 = "ab";
    std::cout << isSubsequence(a3, b3);

    std::string a4 = "ab";
    std::string b4 = "cdab";
    std::cout << isSubsequence(a4, b4);

    return 0;
}

std::string isSubsequence(const std::string &a, const std::string &b){
    std::queue<char> queue;
    for (unsigned int i = 0; i < a.size(); ++i){
        queue.push(a[i]);
    }

    for (unsigned int i = 0; i < b.size(); ++i){
        if (queue.front() == b[i]) queue.pop();
    }

    if (queue.size() == 0) return "subsequence\n";
    else return "not subsequence\n";
}
