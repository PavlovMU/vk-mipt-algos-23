#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> a{1, 2, 3, 4, 6, 9, 10};
    int p1 = 0, p2 = a.size() - 1, sum = 8;
    while (a[p1] + a[p2] != sum) {
        if (a[p1] + a[p2] > sum) {
            p2--;
        }
        else{
            p1++;
        }
    }
    cout<<p1<<" "<<p2<<"\n";
}
