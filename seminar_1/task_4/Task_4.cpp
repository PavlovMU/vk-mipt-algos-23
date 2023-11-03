#include <bits/stdc++.h>

using namespace std;

int main()
{
    //На семинаре говорили, что массив изначально отсортирован.
    vector <int> a{1, 2, 3, 4, 6, 9, 10};
    //sort(a.begin(), a.end());
    int p1 = 0, p2 = a.size() - 1, summ = 8;
    while (a[p1] + a[p2] != summ) {
        if (a[p1] + a[p2] > summ) {
            p2--;
        }
        else{
            p1++;
        }
    }
    cout<<p1<<" "<<p2<<"\n";
}
