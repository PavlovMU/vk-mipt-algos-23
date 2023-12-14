#include <vector>
using namespace std;

int count_seq(int n) {
    if (n==0 || n==1 || n ==2) {
        return n;
    }

    vector<int> dp = {1, 2, 4};
    for (int i=3; i<=n; ++i) {
        dp.push_back(dp[i-3] + dp[i-2] + dp[i-1]);
    }

    return dp[n];
}