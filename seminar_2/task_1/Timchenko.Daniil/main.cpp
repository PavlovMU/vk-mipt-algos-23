#include <string>
#include <queue>
using namespace std;


bool isSubsequence(string a, string b) {
    queue<char> q;
    
    for (auto c : a) {
        q.push(c);
    }

    for (auto c : b) {
        if (q.back() == c) {
            q.pop();
        }
    }

    return q.size() == 0;
}