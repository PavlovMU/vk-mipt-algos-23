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

bool isSameTree(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }
    if (a == nullptr || b == nullptr) {
        return false;
    }
    if (a->value != b->value) {
        return false;
    }
    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}
