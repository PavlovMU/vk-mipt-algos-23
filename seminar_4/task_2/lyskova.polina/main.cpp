#include <iostream>
#include <vector>
#include <queue>

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

bool isSymmetricBFS(std::vector<TreeNode*> array) {
    std::vector<TreeNode*> nodes = array;
    while (nodes.array != 0) {
        std::queue<TreeNode*> queue = {};
        for (auto current : nodes) {
            if (current->left) {
                queue.push(current->left);
            }
            if (current->right) {
                queue.push(current->right);
            }
        }
        long j = queue.size() - 1;
        for (int i = 0; i < queue.size() / 2; ++i) {
            if (queue[i]->data != queue[j]->data) { // j == queue.size() - 1 - i
                return false;
            }
            j--;
        }
        nodes = queue;
    }
    return true;
}
