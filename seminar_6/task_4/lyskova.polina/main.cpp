#include <iostream>
#include <queue>
#include<unordered_map>
#include <vector>
// graph: vertex -> vertex, weight
bool is_tree(std::vector<std::vector<std::pair<long, long>>>& graph, long start) {
    int INF = LONG_MAX;
    std::unordered_map<long, bool> visited;
    for (int i = 1; i <= graph.size(); ++i) {
        visited[i] = false;
    }
    std::unordered_map<int, int> dist; 
    for (auto& vertex : graph) {   
        dist[vertex] = INF;
    }
    dist[start] = 0;
    while (visited.find(false)) {
        u = vertexWithMinWeight(graph, visited, dist);
        for (auto& v : graph[u]) {
            if (graph[u][v].first != 0 && !visited[v]) {
                dist[v] = std::min(dist[v], dist[u] + graph[u][v].second);
            }
        }   
        visited[u] = true;
    }
    return dist;
}

long vertexWithMinWeight(std::vector<std::vector<long>>& graph, 
    std::vector<long> visited, std::unordered_map<int, int> dist) {
    long ind = 0;
    long dist_min = LONG_MAX;
    for (auto& vertex : graph){
        if (dist[vertex] < dist_min && !visited[vertex]) {
            dist_min = dist[vertex];
            ind = vertex;
        }
    }
    return ind;
}
