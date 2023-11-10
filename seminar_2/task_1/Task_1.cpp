#include <bits/stdc++.h>

using namespace std;

int main() {
    //Реализация с помощью очереди
    string a = "abc";
    string b = "ealklbkdlc";
    bool check = false;
    queue <char> s;
    for (int i = 0; i < a.size(); i++) {
        s.push(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        if(s.front() == b[i]) {
            s.pop();
        }
        if(s.empty()) {
            cout<<"YES"<<"\n";
            check = true;
            break;
        }
    }
    if(!check){
        cout<<"NO"<<"\n";
    }
    //Реализация с помощью двух указателей
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()){
        if(a[i] == b[j]) {
            i++;
        }
        j++;
    }
    if(i == a.size()) {
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}
