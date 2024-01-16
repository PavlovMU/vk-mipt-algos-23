#include <iostream>

int PascalTriangle_rec(const int &row, const int &col) {
    if (col == 0 || row == col) {
        return 1;
    } else {
        return PascalTriangle_rec(row - 1, col - 1) + PascalTriangle_rec(row - 1, col);
    }
}

void PascalTriangle_v1(const int &N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << PascalTriangle_rec(i, j) << ' ';
        }
        std::cout << std::endl;
    }
}

void PascalTriangle_v2(const int &N) {
    if (N == 0 || N == 1) {
        return;
    }
    int **triangle = new int *[N];
    for (int i = 0; i < N; i++) {
        triangle[i] = new int[N];
        for (int j = 0; j < N; j++) {
            if (j <= i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = 0;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << triangle[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;
    PascalTriangle_v2(N);
    return 0;
}
