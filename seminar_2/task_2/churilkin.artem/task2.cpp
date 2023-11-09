#include <iostream>
#include <stack>
#include <string>

using namespace std;    

bool isPalindrome(string word) {
    stack<char> s;
    int len = word.length();

    for (int i = 0; i < len; ++i) {
        s.push(word[i]);
    }

    for (int i = 0; i < len; ++i) {
        if (word[i] != s.top()) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    string word;
    cin >> word;

    if (isPalindrome(word)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}
