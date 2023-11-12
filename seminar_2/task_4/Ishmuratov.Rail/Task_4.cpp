#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 8, x = 1, y = 1;
    int l = 0, r = (n-1) * max(x, y), mid = (l + r)/2;
    while (l + 1 < r) {
        mid = (l + r)/2;
        if(mid/x + mid/y < n-1) {
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout<<r + min(x, y)<<"\n";
}
