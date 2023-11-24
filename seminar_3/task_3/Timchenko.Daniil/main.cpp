#include <string>
#include <unordered_map>

using namespace std;


char extraLetter(string a, string b) {
    unordered_map<char, int> b_map;
    for (int i=0; i<b.size(); ++i)
        b_map[b[i]]++;

    for (int i=0; i<a.size(); ++i)
        b_map[a[i]]--;

    char letter;
    for (auto it : b_map)
        if (it.second > 0)
            return it.first;

    return '\0';
}