#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

std::string vertexWithMinWeight(const std::unordered_map<std::string, int>& dist, const std::unordered_map<std::string, bool>& visited) {
    std::string index = "";
    int dist_min = std::numeric_limits<int>::max();

    for (const auto& vertex : dist) {
        if (vertex.second < dist_min && !visited.at(vertex.first)) {
            dist_min = vertex.second;
            index = vertex.first;
        }
    }
    return index;
}

std::unordered_map<std::string, int> dijkstra(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& graph, const std::string& start) {
    const int INF = std::numeric_limits<int>::max();
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, int> dist;

    for (const auto& vertex : graph) {
        visited[vertex.first] = false;
    }

    for (const auto& vertex : graph) {
        dist[vertex.first] = INF;
    }

    dist[start] = 0;

    while (std::any_of(visited.begin(), visited.end(), [](const auto& pair) { return !pair.second; })) {
        std::string u = vertexWithMinWeight(dist, visited);
        for (const auto& v : graph.at(u)) {
            if (graph.at(u).find(v.first) != graph.at(u).end() && graph.at(u).at(v.first) != 0 && !visited[v.first]) {
                dist[v.first] = std::min(dist[v.first], dist[u] + graph.at(u).at(v.first));
            }
        }
        visited[u] = true;
    }

    return dist;
}

int main() {
    std::unordered_map<std::string, std::unordered_map<std::string, int>> graph = {
        {"A", {{"B", 3}, {"C", 1}}},
        {"B", {{"A", 3}, {"C", 7}, {"D", 5}}},
        {"C", {{"A", 1}, {"B", 7}, {"D", 4}}},
        {"D", {{"B", 5}, {"C", 4}}}
    };

    std::unordered_map<std::string, int> shortestDistances = dijkstra(graph, "A");

    // Выводим кратчайшие расстояния от вершины "A" до всех остальных вершин
    for (const auto& pair : shortestDistances) {
        std::cout << "Shortest distance to vertex " << pair.first << " is " << pair.second << std::endl;
    }

    return 0;
}
