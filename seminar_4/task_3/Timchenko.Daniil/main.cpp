#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

int minDepth(Node* root) {
    if (!root) return 0;

    return 1 + min(minDepth(root->left), minDepth(root->right));
}