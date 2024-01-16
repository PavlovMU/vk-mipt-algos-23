#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

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

bool isSameTree(Node *root1, Node *root2) {
    if ((root1 == nullptr) && (root2 == nullptr)) 
        return true;
    if ((root1 == nullptr) || (root2 == nullptr))
        return false;
    if ((root1->data) != (root2->data))
        return false;

    return (isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));
}

int main() {

    return 0;
}