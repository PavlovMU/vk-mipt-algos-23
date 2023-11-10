#include <iostream>
using namespace std;

bool can_print(int n, int time, int x, int y){
    return n <= time / x + time / y;
}

int best_copy_time(int n, int x, int y){
    int l = 0, r = max(x, y)*(n-1);
    while(l < r - 1){
        int mid = (l+r)/2;
        if(can_print(n-1, mid, x, y))
            r = mid;
        else
            l = mid;}
    return r + min(x, y);
}


int main(void){
    cout<<best_copy_time(5, 1, 2)<<endl;
    cout<<best_copy_time(6, 1, 2)<<endl;

    return 0;
}
