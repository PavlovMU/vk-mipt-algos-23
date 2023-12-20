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

bool isSameTree(Tree *a, Tree *b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }
    if ((a == nullptr && b != nullptr) || (a != nullptr && b == nullptr)) {
        return false;
    }
    if (a != nullptr && b != nullptr) {
        if (a->data != b->data) {
            return false;
        } else {
            return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }
    }
}

int main() {
    int *arr = new int[5]{1, 2, 2, 3, 3};
    int *brr = new int[3]{1, 2, 2};
    int *crr = new int[5]{1, 2, 2, 3, 4};
    Tree *t1 = buildTree(arr, 5);
    Tree *t2 = buildTree(arr, 5);
    Tree *t3 = buildTree(brr, 3);
    Tree *t4 = buildTree(crr, 5);
    std::cout << "t1 t2: " << isSameTree(t1, t2) << std::endl;
    std::cout << "t1 t3: " << isSameTree(t1, t3) << std::endl;
    std::cout << "t1 t4: " << isSameTree(t1, t4);
    return 0;
}
