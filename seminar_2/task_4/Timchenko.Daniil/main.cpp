#include <iostream>
using namespace std;

int copyTime(int n, int x, int y) {
    int l = 0, r = (n-1) * max(x, y);

    while (l + 1 < r) {
        int mid = (l+r) / 2;

        if (mid/x + mid/y < n-1) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r + min(x, y);
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << copyTime(n, x, y) << endl;
}