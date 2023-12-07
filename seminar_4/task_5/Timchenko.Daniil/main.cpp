#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

bool isSameTree(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;

    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}
