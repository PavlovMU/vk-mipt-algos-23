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
}

Node *buildTree(std::vector<int> &a, int i) {
    if (i >= a.size()) {
        return nullptr;
    }

    Node *root = TreeNode(a[i]);
    root->left = buildTree(a, 2*i + 1);
    root->right = buildTree(a, 2*i + 2);
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

bool isSymmetricBFS(Node *root) {
    std::vector<int> nodes;
    TreeToVec(root, 0, nodes);
    while (nodes.size() != 0) {
        
    }


    return true;
}

int main() {
    std::vector<int> a = {};



    return 0;
}