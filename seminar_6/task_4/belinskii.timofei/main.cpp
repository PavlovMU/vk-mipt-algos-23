#include <iostream>
#include "vector"
#include "queue"

class Graph {
    int numberNodes;
    int **matrix;

public:
    void enter(const bool &weights = false) {
        if (weights) {
            /// Вводить граф необходимо в формате
            /// 1 2 1 // вершина_1 вершина_2 вес_ребра
            /// 1 3 3
            /// -1 // ввод оканчивается -1

            std::string in;
            int v, w, u = 0;
            while (true) {
                std::getline(std::cin, in);
                if (in.find(' ') == -1) {
                    break;
                }
                u = std::stoi(in.substr(0, in.find(' '))) - 1;
                in = in.substr(in.find(' ') + 1, in.size() - in.find(' ') - 1);
                v = std::stoi(in.substr(0, in.find(' '))) - 1;
                in = in.substr(in.find(' ') + 1, in.size() - in.find(' ') - 1);
                w = std::stoi(in.substr(0, in.find(' ')));
                matrix[u][v] = w;
                matrix[v][u] = w;
            }
        } else {
            /// Вводить граф необходимо в формате
            /// 1: 2, 3 // вершина: сосед_1, сосед_2, ...
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
    }

    void print() {
        for (int i = 0; i < numberNodes; i++) {
            for (int j = 0; j < numberNodes; j++) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    void dfs(int *visited, const int &current = 0, const int &color = 1, bool *cycle = nullptr) {
        if (cycle == nullptr) {
            cycle = new bool{false};
        }
        visited[current] = color;
        for (int j = 0; j < numberNodes; j++) {
            if (matrix[current][j] != 0 && visited[j] == 0) {
                dfs(visited, j, color, cycle);
            } else if (visited[j] != 0) {
                *cycle = true;
            }
        }
    }

    void bfs(int *visited, const int &start = 0, bool *cycle = nullptr) {
        std::queue<int> nodes;
        std::queue<int> parents;
        nodes.push(start);
        parents.push(-1);
        while (!nodes.empty()) {
            int current = nodes.front();
            int previous = parents.front();
            nodes.pop();
            parents.pop();
            visited[current] = 1;
            for (int i = 0; i < numberNodes; i++) {
                if (matrix[current][i] != 0 && previous != i && visited[i] == 0) {
                    nodes.push(i);
                    parents.push(current);
                } else if (visited[i] != 0 && cycle != nullptr) {
                    *cycle = true;
                }
            }
        }
    }

    std::pair<int, int *> find_connected_components() {
        int col = 1;
        int *vis = new int[numberNodes];
        for (int i = 0; i < numberNodes; i++) {
            vis[i] = 0;
        }
        for (int i = 0; i < numberNodes; i++) {
            if (vis[i] == 0) {
                dfs(vis, i, col);
                col++;
            }
        }
        return std::make_pair(col - 1, vis);
    }

    bool has_cycle() {
        int *vis = new int[numberNodes];
        bool *res = new bool{false};
        for (int i = 0; i < numberNodes; i++) {
            vis[i] = 0;
        }
        for (int i = 0; i < numberNodes; i++) {
            if (vis[i] == 0) {
                dfs(vis, i, 1, res);
                if (*res) {
                    return true;
                }
            }
        }
        return false;
    }

    bool is_tree() {
        int *vis = new int[numberNodes];
        for (int i = 0; i < numberNodes; i++) {
            vis[i] = 0;
        }
        bool *res = new bool{false};
        bfs(vis, 0, res);
        if (*res) {
            return true;
        }
        for (int i = 0; i < numberNodes; i++) {
            if (vis[i] == 0) {
                return false;
            }
        }
        return true;
    }

    void distances_from(const int &start, int *visited, int *distances) {
        visited[start] = 1;
        for (int i = 0; i < numberNodes; i++) {
            if (matrix[start][i] != 0 && visited[i] == 0) {
                distances[i] = std::min(distances[i], matrix[start][i] + distances[start]);
            }
        }
        int min_length = INT32_MAX, next = -1;
        for (int i = 0; i < numberNodes; i++) {
            if (min_length > distances[i] && visited[i] == 0) {
                min_length = distances[i];
                next = i;
            }
        }
        if (next != -1) {
            distances_from(next, visited, distances);
        }
    }

    std::pair<int, std::vector<int>> dijkstra(const int &start, const int &finish) {
        int *vis = new int[numberNodes];
        int *dis = new int[numberNodes];
        int length;
        std::vector<int> path;
        for (int i = 0; i < numberNodes; i++) {
            vis[i] = 0;
            dis[i] = INT32_MAX;
        }
        dis[start - 1] = 0;
        distances_from(start - 1, vis, dis);
        length = dis[finish - 1];
        int current = start - 1;
        while (current != finish - 1) {
            for (int i = 0; i < numberNodes; i++) {
                if (matrix[current][i] != 0 && dis[current] + matrix[current][i] == dis[i]) {
                    path.push_back(current + 1);
                    current = i;
                }
            }
        }
        path.push_back(finish);
        return std::make_pair(length, path);
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
    /*
        5
        1 2 10
        2 3 2
        1 3 2
        3 4 10
        2 4 1
        4 5 1
        3 4 15
        -1
     */
    getline(std::cin, in);
    n = stoi(in);
    Graph g1(n);
    g1.enter(true);
    std::pair<int, std::vector<int>> res1 = g1.dijkstra(1, 5);
    std::cout << res1.first << std::endl;
    for (int &it: res1.second) {
        std::cout << it << ' ';
    }
    return 0;
}
