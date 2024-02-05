#include <vector>
#include <iostream>
using namespace std;

void pascal_triangle(int n) {
    vector<vector<int>> dp;
    for (int i=1; i<=n; ++i) {
        vector<int> tmp;
        for (int j=1; j<=i; ++j) {
            tmp.push_back(1);
        }
        dp.push_back(tmp);
    }

    for (int row=1; row<n; ++row) {
        for (int col=1; col<row; ++col) {
            dp[row][col] = dp[row-1][col-1] + dp[row-1][col];
        }
    }

    for (int i=0; i<dp.size(); ++i) {
        int x = dp[i].size();
        for (int j=0; j<x; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}