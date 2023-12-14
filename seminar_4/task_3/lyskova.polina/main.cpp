#include <iostream>

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

long minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left != nullptr && root->right != nullptr) {
        return 1 + std::min(minDepth(root->left), minDepth(root->right));

    }
    if (root->left != nullptr) {
        return 1 + minDepth(root->left);
    }
    if (root->right != nullptr) {
        return 1 + minDepth(root->right);
    }
    return 1;
}
