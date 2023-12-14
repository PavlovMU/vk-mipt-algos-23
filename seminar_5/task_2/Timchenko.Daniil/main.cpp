#include <vector>
using namespace std;

int findLIS(vector<int> a) {
    int n = a.size();
    if (n == 0 || n == 1)
        return n;
    
    vector<int> dp(n, 1);
    for (int i=1; i<n; ++i) {
        if (a[i-1] < a[i]) {
            dp[i] = dp[i-1] + 1;
        }
    }

    return *max_element(dp.begin(), dp.end());
}