#include <iostream>
#include <unordered_map>
using namespace std;

string extra_letter(string a, string b){
    unordered_map<char, int> m;
    string ans;
    for(char c : b)
        m[c]++;
    for(char c : a)
        m[c]--;
    for(auto it : m)
        for(int i=0; i<it.second; i++)
            ans.push_back(it.first);
    return ans;
}

int main(void){
    cout<<extra_letter("aaa", "akkaoabb");

    return 0;
}
