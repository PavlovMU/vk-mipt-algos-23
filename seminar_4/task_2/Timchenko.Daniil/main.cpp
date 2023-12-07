#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

bool isMirror(Node* a, Node* b) {
    if (!a && !b) return true;

    if (a && b && a->val == b->val)
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);

    return false;
}

bool isSymmetric(Node* root) {
    isMirror(root, root);
}