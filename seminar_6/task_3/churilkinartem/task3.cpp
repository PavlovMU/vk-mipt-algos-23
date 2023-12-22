#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

bool is_tree(const std::unordered_map<int, std::vector<int>>& graph, int start) {
    std::unordered_set<int> visited;
    std::queue<int> queue;
    std::unordered_map<int, int> parent;

    queue.push(start);
    parent[start] = -1;

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        visited.insert(vertex);
        for (int neighbor : graph.at(vertex)) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push(neighbor);
                parent[neighbor] = vertex;
            } else {
                if (parent[vertex] != neighbor) {
                    return false;
                }
            }
        }
    }
    return visited.size() == graph.size();
}

int main() {
    std::unordered_map<int, std::vector<int>> graph = {
        {1, {2, 3}},  // Вершина 1 связана с вершинами 2 и 3
        {2, {1}},     // Вершина 2 связана с вершиной 1
        {3, {1}}      // Вершина 3 связана с вершиной 1
    };

    bool isTree = is_tree(graph, 1);

    std::cout << "Это " << (isTree ? "дерево" : "не дерево") << std::endl;

    return 0;
}
