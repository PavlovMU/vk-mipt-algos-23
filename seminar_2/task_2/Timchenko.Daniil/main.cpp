#include <string>
#include <stack>
using namespace std;

bool isPalindrome(string a) {
    stack<char> s;

    for (auto c : a) {
        s.push(c);
    }

    for (auto c : a) {
        if (c != s.top())
            return false;
        s.pop();
    }

    return true;
}