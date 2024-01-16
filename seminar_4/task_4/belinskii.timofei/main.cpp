#include <iostream>
#include "queue"

struct Tree {
    int data;
    Tree *left;
    Tree *right;

    void printLNR() {
        if ((*this).left != nullptr) {
            (*this).left->printLNR();
        }
        std::cout << data << ' ';
        if ((*this).right != nullptr) {
            (*this).right->printLNR();
        }
    }

    void printBFS() {
        std::queue<Tree *> desc;
        desc.push(&(*this));
        while (!desc.empty()) {
            std::cout << desc.front()->data << ' ';
            if (desc.front()->left != nullptr) {
                desc.push(desc.front()->left);
            }
            if (desc.front()->right != nullptr) {
                desc.push(desc.front()->right);
            }
            desc.pop();
        }
    }
};

Tree *buildTree(int *arr, const int &size, const int &cur = 0) {
    if (cur >= size) {
        return nullptr;
    }
    Tree *root = new Tree;
    root->data = arr[cur];
    root->left = buildTree(arr, size, 2 * cur + 1);
    root->right = buildTree(arr, size, 2 * cur + 2);
    return root;
}

int minDepth(Tree *root, int depth = 0) {
    if (root == nullptr) {
        return 0;
    }
    if ((root->left == nullptr) && (root->right == nullptr)) {
        return ++depth;
    }
    if ((root->left != nullptr) && (root->right != nullptr)) {
        return std::min(minDepth(root->left, depth + 1), minDepth(root->right, depth + 1));
    }
    if (root->left != nullptr) {
        return minDepth(root->left, depth + 1);
    }
    if (root->right != nullptr) {
        return minDepth(root->right, depth + 1);
    }
}

int main() {
    int *arr = new int[11]{11, 8, 16, 2, 9, 6, 0, 7, 0, 0, 9};
    Tree *t1 = buildTree(arr, 11);
    t1->left->left->right = nullptr;
    t1->left->right->left = nullptr;
    t1->right->right = nullptr;
    ///           1
    ///     8           16
    ///  2     9      6
    /// 7       9
    std::cout << minDepth(t1);
    return 0;
}
