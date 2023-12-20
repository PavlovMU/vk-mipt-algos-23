#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data = 0, Node *_left = nullptr, Node *_right = nullptr) {
        data = _data;
        left = _left;
        right = _right;
    }

    Node *buildTree(std::vector<int> arr, int i) {
        if (i >= arr.size()) {
            return nullptr;
        }

        Node *root = new Node(arr[i]);
        root->left  = buildTree(arr, 2*i + 1);
        root->right = buildTree(arr, 2*i + 2);

        return root;
    }

    Node *preorderPrint(Node *root) {
        if (root == nullptr)
            return nullptr;

        std::cout << " [" << root->data << "] ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }
};


int main() {
    size_t len;
    std::cin >> len;
    std::vector<int> arr(len);

    for (size_t i = 0; i < len; ++i) {
        std::cin >> arr[i];
    } 

    // for (size_t i = 0; i < arr.size(); ++i) {
    //     std::cout << arr[i] << " ";
    // } 
    std::cout << std::endl;

    Node *root = root->buildTree(arr, 0);
    root->preorderPrint(root);

}