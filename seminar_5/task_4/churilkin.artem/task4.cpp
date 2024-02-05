#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
struct Node {
    int val;
    Node* left;
    Node* right;
    
    // Конструктор
    Node(int val = 0, Node* left = nullptr, Node* right = nullptr) 
        : val(val), left(left), right(right) {}
};

int MIN_INT = std::numeric_limits<int>::min();

int max_sum = MIN_INT;
std::vector<int> max_path;



std::pair<int, std::vector<int>> dfs(Node* node) {
    if (node == nullptr) {
        return {0, {}};
    }

    auto [left_sum, left_path] = dfs(node->left);
    auto [right_sum, right_path] = dfs(node->right);

    std::vector<int> current_max_path;
    int current_max_sum = 0;

    if (left_sum > right_sum) {
        current_max_path = left_path;
    } else {
        current_max_path = right_path;
    }

    if (current_max_path.empty() || left_sum > right_sum) {
        current_max_path.push_back(node->val);
    } else {
        current_max_path.push_back(node->val);
    }

    current_max_sum = std::max({left_sum, right_sum, 0}) + node->val;

    if (current_max_sum > max_sum) {
        max_sum = current_max_sum;
        max_path = current_max_path;
    }

    return {current_max_sum, current_max_path};
}

std::vector<int> find_max_path_summ(Node* root) {
    dfs(root);
    return max_path;
}

int main() {
    // Создание тестового дерева
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->right->left = new Node(20);
    root->right->right = new Node(1);

    std::vector<int> result = find_max_path_summ(root);

    std::cout << "Max Sum: " << max_sum << std::endl;
    std::cout << "Max Path: ";
    for (int val : max_path) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
