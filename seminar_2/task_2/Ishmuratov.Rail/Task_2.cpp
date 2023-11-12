#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        if(a[l] != a[r]) {
            cout<<"NO"<<"\n";
            return 0;
        }
        l++;
        r--;
    }
}
