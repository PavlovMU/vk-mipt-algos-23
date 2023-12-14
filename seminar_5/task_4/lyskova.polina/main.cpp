#include <iostream>
#include <vector>
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int value;

    TreeNode() {
        left = nullptr;
        right = nullptr;
        value = 0;
    }
    TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        this->left = left;
        this->right = right;
        this->value = value;
    }
};

std::pair<long, std::vector<long>> dfs(TreeNode* node) {
    if (node == nullptr) {
        return std::pair(0, std::vector<long>());
    }
    std::pair<long, std::vector<long>> left = dfs(node->left);
    std::pair<long, std::vector<long>> right = dfs(node->right);
    std::vector<long> current_max_path;
    if (left.first > right.first) {
        current_max_path = left.second;
        current_max_path.emplace_back(node->value);
    } else {
        current_max_path = right.second;
        current_max_path.emplace_back(node->value);
    }
    long current_max_sum = std::max(left.first, right.first) + node->value;
    if (left.first + right.first + node->value > current_max_sum) {
        current_max_sum = left.first + right.first + node->value;
        current_max_path = left.second;
        current_max_path.emplace_back(node->value);
        for (auto& i : right.second) {
            current_max_path.emplace_back(i);
        }
    }
    return std::pair(current_max_sum, current_max_path);
}

std::vector<long> find_max_path_sum(TreeNode* root) {
    return dfs(root).second;
}
