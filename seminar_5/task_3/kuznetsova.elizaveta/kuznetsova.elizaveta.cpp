#include <iostream> 
#include <vector>


std::vector<std::vector<size_t>> trianglePascal(size_t number) {
    
    std::vector<std::vector<size_t>> dp;

    for (int i = 0; i <= number; ++i) {
        std::vector<size_t> tmp;
        for (int j = 0; j <= i; ++j) {
            tmp.push_back(1);
        }
        dp.push_back(tmp);
    }

    // for (int i = 0; i < number; ++i) {
    //     std::vector tmp = dp[i];
    //     for (int j = 0; j <= i; ++j) {
    //         std::cout << tmp[j];
    //     }
    //     std::cout << std::endl;
    // } 



    for (size_t row = 2; row < number; ++row) {
        for (size_t col = 1; col < row; ++col) {
            dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
        }
    }
    return dp;
}

int main() {
    size_t number;

    std::cin >> number;
    
    std::vector<std::vector<size_t>> triangle = trianglePascal(number);


    for (int i = 0; i < number; ++i) {
        std::vector tmp = triangle[i];
        for (int j = 0; j <= i; ++j) {
            std::cout << tmp[j];
        }
        std::cout << std::endl;
    } 
}