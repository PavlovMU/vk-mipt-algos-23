#include <iostream>
#include <algorithm>
#include <vector>

class Node {
    int data;
    Node *left;
    Node *right;
};

bool isSameTree(Node *a, Node *b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }
    
    if (a == nullptr || b == nullptr) {
        return false;
    }

    if (a->data != b->data) {
        return false
    }

    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}


int main() {
    
}