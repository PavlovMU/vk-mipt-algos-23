#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 0, a = 15, r = a, mid = (l+r)/2;
    while (l <= r) {
        mid = (l+r) / 2;
        if(mid * mid > a) {
            r = mid - 1;
        }
        if(mid * mid < a) {
            l = mid + 1;
        }
    }
    cout<<r<<"\n";
}
