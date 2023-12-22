#include <iostream>
#include <algorithm> // Для использования std::min

// Определение структуры TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Конструктор
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) 
        : val(val), left(left), right(right) {}
};

int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (root->left && root->right) {
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
    if (root->left) {
        return 1 + minDepth(root->left);
    }
    if (root->right) {
        return 1 + minDepth(root->right);
    }
    return 1; // Если у узла нет потомков, его глубина равна 1
}

int main() {
    // Строим дерево
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Находим минимальную глубину
    std::cout << minDepth(root); 

    return 0;
}
