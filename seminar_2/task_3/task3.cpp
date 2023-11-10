#include <iostream>
#include <cmath>
using namespace std;

int integer_square(int n){
    int l = 0, r = n;
    while (l <= r){
        int mid = (l+r) / 2;
        if(mid * mid > n)
            r = mid-1;
        else if(mid*mid < n)
            l = mid+1;
        else
            return mid;}
    return r;
}

int main(void){
    int mistakes = 0;
    for(int i=0; i<=10000; i++)
        mistakes+=integer_square(i)!=int(sqrt(i));
    cout<<mistakes;
    return 0;
}
