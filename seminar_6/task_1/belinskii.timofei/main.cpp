#include <iostream>
#include "vector"

class Graph {
    int numberNodes;
    int **matrix;

public:
    void enter() {
        /// Вводить граф необходимо в следующем виде
        /// 3
        /// 1: 2, 3
        /// 2: 1, 3
        /// 3: 1, 2

        for (int i = 0; i < numberNodes; i++) {
            std::string in;
            std::getline(std::cin, in);
            int u = std::stoi(in.substr(0, in.find(':'))) - 1;
            in = in.substr(in.find(' ') + 1, in.size() - in.find(' ') - 1);
            while (in.find(' ') != -1) {
                int v = std::stoi(in.substr(0, in.find(','))) - 1;
                matrix[u][v] = 1;
                matrix[v][u] = 1;
                in = in.substr(in.find(' ') + 1, in.size() - in.find(' ') - 1);
            }
            int v = std::stoi(in.substr(0, in.find(','))) - 1;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }

    void print() {
        for (int i = 0; i < numberNodes; i++) {
            for (int j = 0; j < numberNodes; j++) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    void dfs(int *visited, const int &current = 0) {
        visited[current] = 1;
        for (int j = 0; j < numberNodes; j++) {
            if (matrix[current][j] == 1 && visited[j] == 0) {
                dfs(visited, j);
            }
        }
    }

    int find_connected_components() {
        int res = 0;
        int *vis = new int[numberNodes];
        for (int i = 0; i < numberNodes; i++) {
            vis[i] = 0;
        }
        for (int i = 0; i < numberNodes; i++) {
            if (vis[i] == 0) {
                dfs(vis, i);
                res++;
            }
        }
        return res;
    }

    Graph(const int &num) {
        numberNodes = num;
        matrix = new int *[numberNodes];
        for (int i = 0; i < numberNodes; i++) {
            matrix[i] = new int[numberNodes];
            for (int j = 0; j < numberNodes; j++) {
                matrix[i][j] = 0;
            }
        }
    }
};


int main() {
    int n;
    std::string in;
    getline(std::cin, in);
    n = stoi(in);
    Graph g1(n);
    g1.enter();
    std::cout << g1.find_connected_components();
    return 0;
}
