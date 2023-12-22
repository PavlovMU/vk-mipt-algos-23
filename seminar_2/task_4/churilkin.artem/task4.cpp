#include <iostream>

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x > y ? y : x;
}

int copyTime(int n, int x, int y) {
    int l = 0;
    int r = (n - 1) * max(x, y);
    int mid = 0;
    while (l + 1 < r) {
        mid = (r + 1) / 2;
        if ( mid/x + mid/y < n - 1){
            l = mid;
        }
        else {
            r = mid;
        }

    }

    return r + min(x,y);

}

int main() {

    return 0;
}