#include "tree.hpp"

Node* BuildTree(int arr[], int size, int i);

Node* BuildTree(int arr[], int size, int i)
{
    if (i >= size)
        return nullptr;

    Node* root = new Node(arr[i]);

    root->left_  = BuildTree(arr, size, 2 * i + 1);

    root->right_ = BuildTree(arr, size, 2 * i + 2);

    return root;
}

int main()
{
    int arr[7] = {8, 9, 11, 7, 16, 3, 1};

    Tree tree;

    tree.root_ = BuildTree(arr, 7, 0);

    tree.Dump(tree.root_);

    return 0;
}