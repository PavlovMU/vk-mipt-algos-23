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

TreeNode* buildTree(std::vector<long> array, int i) {
    if (i >= array.size()) {
        return nullptr;
    }
    TreeNode* root = TreeNode(array[i]);
    root->left = buildTree(array, 2 * i + 1);
    root->right = buildTree(array, 2 * i + 2);
    return root;
}
