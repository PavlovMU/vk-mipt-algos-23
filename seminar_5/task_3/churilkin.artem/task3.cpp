#include<vector>


std::vector< std::vector <int> > pascal_triangle(int row, int col) {
    if (col == 0 or row == col) return {{1}};
    int n = 6;
    std::vector< std::vector <int> > dp;
    for (int i = 1; i <= n; i++){
        std::vector<int> tmp;
        for(int j = 1; j<= i; j++){ tmp.push_back(1); }
        dp.push_back(tmp);
    }
    for (row = 1; row < n; ++row) {
        for (col = 1; col < row; col++){
            dp[row][col] = dp[row-1][col-1] + dp[row-1][col];
        }
    }
    
    return dp;
}

int main() {
    return 0;
}