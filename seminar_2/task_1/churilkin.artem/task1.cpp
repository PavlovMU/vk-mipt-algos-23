#include <string>
#include <queue>
#include <iostream>

using namespace std; 

bool subCheck(std::string a, std::string b)
{
    std::queue<char> q;
    for (char el : b) {
        q.push(el);
    }
    for (char el : a) {
        if (q.front() == el) q.pop();
    }

    return q.empty();
}

int main() {
    string str1 = "ACBFC";
    string str2 = "ABC";
    cout << subCheck(str1, str2);
    return 0;
}