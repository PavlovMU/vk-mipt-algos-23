#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

Node* newNode(int val = 0, Node* left = nullptr, Node* right = nullptr) {
    Node *x = (Node*)malloc(sizeof(Node));
    x->val = val;
    x->left = left;
    x->right = right;
    return x;
}

void freeNode(Node* x) {
    if (!x->left) freeNode(x->left);
    if (!x->right) freeNode(x->right);
    free(x);
}

Node* buildTree(vector<int> a, int i) {
    if (i >= a.size()) {
        return nullptr;
    }
    Node *root = newNode(a[i]);
    root->left = buildTree(a, 2*i+1);
    root->right = buildTree(a, 2*i+2);

    return root;
}