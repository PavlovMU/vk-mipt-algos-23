#include <iostream>
#include <vector>

bool has_cycle(std::vector<std::vector<long>>& graph) {
    std::vector<long> visited;
    for (auto& v : graph) {
        if (!std::find(visited.begin(), visited.end(), v) != visited.end()) {
            if (dfs(graph, v, 0, visited)) {
                return true;
            }
        }
    }
    return false;
}

void dfs(std::vector<long, std::vector<long>>& graph, int vertex,
    int parent, std::vector<long>& visited) {
    visited.emplace_back(vertex);
    for (auto& neighbor : graph[vertex]) {
        if (neighbor != parent) {
            if (!std::find(visited.begin(), visited.end(), neighbor) != visited.end() ||
                dfs(graph, neighbor, vertex, visited)) {
                return true;
            }
        }
    }
    return false;
}

