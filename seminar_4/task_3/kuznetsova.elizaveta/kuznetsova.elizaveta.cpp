#include <iostream>
#include <algorithm>

class Node {
    int data;
    Node *left;
    Node *right;
};


int minDerth(Node *root) {
    if (!root) {
        return 0;
    }

    if (root->left != nullptr && root->right != nullptr) {
        return (1 + std::min(minDerth(root->left), minDerth(root->right)))
    }
    if (root->left != nullptr) {
        return (1 + minDerth(root->left))
    }  
    if (root->right != nullptr) {
        return (1 + minDerth(root->right))
    }

    return 1;
}

int main() {
    
}