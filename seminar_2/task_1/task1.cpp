#include <iostream>
#include <queue>
using namespace std;

bool is_substring(string s1, string s2){
    queue<char> q;
    for(size_t i=0; i<s1.size(); i++)
        q.push(s1[i]);
    for(size_t i=0; i<s2.size(); i++)
        if(s2[i] == q.front())
            q.pop();
    return q.size() == 0;
}

int main(void){
    cout<<is_substring("ABC", "AFHFHFHJBKFKFLLC")<<endl;
    cout<<is_substring("", "AF")<<endl;
    cout<<is_substring("A", "KJLKHHA")<<endl;
    cout<<is_substring("BA", "ABH")<<endl;
    cout<<is_substring("ABC", "ABC")<<endl;
    return 0;
}

