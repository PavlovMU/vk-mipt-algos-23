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

int main() {
    int N;
    std::cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    /*IN:
7
16 11 18 9 13 17 21
    дерево поиска => dfs сортирует
OUT_LNR: 9 11 13 16 17 18 21*/

    Tree *t1 = buildTree(arr, N);
    std::cout << "LNR: ";
    t1->printLNR();
    std::cout << "\nBFS: ";
    t1->printBFS();
    return 0;
}
