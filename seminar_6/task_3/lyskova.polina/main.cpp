#include <iostream>
#include <queue>
#include<unordered_map>
#include <vector>

bool is_tree(std::vector<std::vector<long>>& graph, long start) {
    std::vector<long> visited;
    std::queue<long> queue = { start };
    std::unordered_map<long, long> parent = { {start, 0} };
    while (queue) {
        long vertex = queue.pop();
        visited.emplace_back(vertex);
        for (auto& neighbor : graph[vertex]) {
            if (!std::find(visited.begin(), visited.end(), neighbor) != visited.end()) {
                queue.push(neighbor);
                parent[neighbor] = vertex;
            }
            else {
                if (parent[vertex] != neighbor) {
                    return false;
                }
            }
        }
    }
    return visited.size() == graph.size();
}
