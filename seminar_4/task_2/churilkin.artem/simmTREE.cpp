#include <iostream>
#include <vector>
#include <queue> // Для использования стандартной очереди

// Определение структуры TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Конструктор
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) 
        : val(val), left(left), right(right) {}
};

bool isSymmetricBFS(TreeNode* bt) {
    std::queue<TreeNode*> nodes;
    nodes.push(bt);

    while (!nodes.empty()) {
        std::queue<TreeNode*> queue;
        while (!nodes.empty()) {
            TreeNode* current = nodes.front();
            nodes.pop();

            if (current->left) {
                queue.push(current->left);
            }
            if (current->right) {
                queue.push(current->right);
            }
        }

        std::vector<int> levelValues;
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
            levelValues.push_back(node->val);
        }

        int j = queue.size() - 1;
        for (int i = 0; i<queue.size(); ++i) {
            if (levelValues[i] != levelValues[j]) {
                return false;
            }
            j--;
        }

        nodes = queue; // Продолжаем обход по уровням
    }
    return true;
}

int main() {
    // Строим дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Проверяем симметричность
    std::cout << isSymmetricBFS(root); // Выведет 1, так как дерево симметрично

    return 0;
}
