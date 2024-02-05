#include <iostream>
// Определение структуры TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Конструктор
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) 
        : val(val), left(left), right(right) {}
};

bool isSameTree(TreeNode* a,TreeNode* b) {
    if (a == nullptr and b == nullptr)
    {
        return true;
    }
    if (a == nullptr or b == nullptr)
    {
         return false;
    }
    if (a->val != b->val)
    {
        return false;
    }

    return isSameTree(a->left, b->left) and isSameTree(a->right, b->right);
}

int main() {
    TreeNode* a = new TreeNode(3);
    a->left = new TreeNode(9);
    a->right = new TreeNode(20);
    a->right->left = new TreeNode(15);
    a->right->right = new TreeNode(7);

    TreeNode* b = new TreeNode(3);
    b->left = new TreeNode(9);
    b->right = new TreeNode(20);
    b->right->left = new TreeNode(15);
    b->right->right = new TreeNode(7);

    std::cout << isSameTree(a, b); // выдаст 1, так как a и b одинаковые деревья
    return 0;
}