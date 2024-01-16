#include <iostream>
#include <cstdlib>
#include <vector>

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *TreeNode(int d) {
    Node *root = new Node;
    root->data = d;
    return root;
}

Node *buildTree(std::vector<int> &a, int i) {
    if (i >= a.size()) {
        return nullptr;
    }

    Node *root = TreeNode(a[i]);
    root->left = buildTree(a, 2*i + 1);
    root->right = buildTree(a, 2*i + 2);

    return root;
}

std::vector<int> TreeToVec(Node *root, int i, std::vector<int> &vec) {
    if (root == nullptr)
        return vec;

    if (root->left != nullptr)
        TreeToVec(root->left, i, vec);
    else {
        vec[i] = root->data;
        TreeToVec(root->right, i+1, vec);
    }

    return (vec);
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    Node *root = buildTree(a, 0);

    std::cout << root->data << root->left->data << root->right->data << std::endl;
    return 0;
}