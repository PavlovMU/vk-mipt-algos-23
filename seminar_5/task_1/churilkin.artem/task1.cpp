// последовательность без трех единиц подряд

#include <vector>

int count_sequences(int n){
    if ( n == 0 or n == 1 or n == 2) return n;
    std::vector<int> dp = {1, 2, 4};
    for (int i = 3; i<= n; i++){
        dp.push_back(dp[i-1]+dp[i-2]+dp[i-3]);
    }
    return dp[n];
}

int main()
{
    return 0;
}