#include <iostream>
#include <vector>
#include <map>

// Функция поиска в глубину
void dfs(const std::vector<std::vector<int>>& graph, int v, std::map<int, bool>& visited, std::vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int i : graph[v]) {
        if (!visited[i]) {
            dfs(graph, i, visited, component);
        }
    }
}

// Функция поиска связанных компонент в графе
std::vector<std::vector<int>> find_connected_components(const std::vector<std::vector<int>>& graph) {
    std::map<int, bool> visited;
    for (int i = 0; i < graph.size(); ++i) {
        visited[i] = false;
    }

    std::vector<std::vector<int>> connected_components;
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            std::vector<int> component;
            dfs(graph, i, visited, component);
            connected_components.push_back(component);
        }
    }
    return connected_components;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {1},       // Вершина 0 связана с вершиной 1
        {0, 2},    // Вершина 1 связана с вершинами 0 и 2
        {3},       // Вершина 2 связана с вершиной 3
        {2, 4},    // Вершина 3 связана с вершинами 2 и 4
        {3}        // Вершина 4 связана с вершиной 3
    };

    std::vector<std::vector<int>> components = find_connected_components(graph);

    // Вывод связанных компонент
    for (const auto& component : components) {
        for (int vertex : component) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
