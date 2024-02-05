#include <iostream>
#include <vector>

// Определение структуры TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) 
        : val(val), left(left), right(right) {}
};

TreeNode* buildTree(const std::vector<int>& arr, int i) {
    if (i >= arr.size()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);
    return root;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = buildTree(arr, 0);
    return 0;
}
