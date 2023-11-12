#include <bits/stdc++.h>

using namespace std;

int main() {
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