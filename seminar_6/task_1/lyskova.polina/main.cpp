#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<long> find_connected_components(std::vector<std::vector<long>>& graph) {
    std::unordered_map<int, bool> visited;
    for (int i = 1; i <= graph.size(); ++i) {
        visited[i] = false;
    }
    std::vector<std::vector<long>> components;
    for (int i = 0; i < graph.size(); ++i) {
        long currentNode = i + 1;
        if (!visited[currentNode]) {
            std::vector<long> component = {};
            dfs(graph, currentNode, visited, component);
            components.emplace_back(component);
        }
    }
    return components;
}

void dfs(std::vector<long, std::vector<long>>& graph, int vertex,
    std::vector<bool>& visited, std::vector<long>& component) {
    visited[vertex] = true;
    component.emplace_back(vertex);
    for (auto& i : graph[vertex]) {
        if (!visited[i]) {
            dfs(graph, i, visited, component);
        }
    }
}
 // –¿— –¿— ¿
/*
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<long> find_connected_components(std::vector<std::vector<long>>& graph) {
    std::unordered_map<int, int> visited;
    for (int i = 1; i <= graph.size(); ++i) {
        visited[i] = 0;
    }
    int color = 0;
    for (auto& node : graph) {
        if (visited[node] == 0) {
            color++;
            dfs(graph, node, visited, color);
        }
    }
    return visited;
}

void dfs(std::vector<long, std::vector<long>>& graph, int vertex,
    std::vector<bool>& visited, int color) {
    visited[vertex] = color;
    for (auto& i : graph[vertex]) {
        if (visited[i] == 0) {
            dfs(graph, i, visited, color);
        }
    }
}
*/