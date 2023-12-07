#include <vector>
using namespace std;

int maxMinMultiplication(vector<int> data) {
    int n = data.size();
    switch (n) {
        case 0: return -1;
        case 1: return data[0]*data[0];
        case 2: return data[0]*data[1];
    }

    int min_i = 1, max_i = 2;
    for (int i = 1; i < n; i = 2*i+1) {
        min_i = i;
    }
    for (int i = 1; i < n; i = 2*i+2) {
        max_i = i;
    }

    return data[min_i]*data[max_i];
}