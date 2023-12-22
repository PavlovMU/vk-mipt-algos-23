#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Функция поиска в глубину
bool dfs(const std::unordered_map<int, std::vector<int>>& graph, int vertex, int parent, std::unordered_set<int>& visited) {
    visited.insert(vertex);
    for (int neighbor : graph.at(vertex)) {
        if (neighbor != parent) {
            if (visited.count(neighbor) || dfs(graph, neighbor, vertex, visited)) {
                return true;
            }
        }
    }
    return false;
}

// Функция проверки наличия циклов в графе
bool has_cycle(const std::unordered_map<int, std::vector<int>>& graph) {
    std::unordered_set<int> visited;
    for (const auto& entry : graph) {
        int vertex = entry.first;
        if (visited.count(vertex) == 0) {
            if (dfs(graph, vertex, -1, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::unordered_map<int, std::vector<int>> graph = {
        {1, {2, 3}},  // Вершина 1 связана с вершинами 2 и 3
        {2, {1, 3}},  // Вершина 2 связана с вершинами 1 и 3
        {3, {1, 2}}   // Вершина 3 связана с вершинами 1 и 2
    };

    bool hasCycle = has_cycle(graph);

    std::cout << "Граф " << (hasCycle ? "содержит циклы" : "не содержит циклов") << std::endl;

    return 0;
}
