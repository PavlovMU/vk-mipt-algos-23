#ifndef TREE_HPP_
#define TREE_HPP_

#include <iostream>

class Node
{
    public:

        int data_ = 0;

        Node* left_ = nullptr;

        Node* right_ = nullptr;

        Node(int data = 0, Node* left = nullptr, Node* right = nullptr) : data_{data}, left_{left}, right_{right} {}
};

class Tree
{
    public:

        Node* root_ = nullptr;



        Tree() {}

        Tree(const Tree& rhs) = delete;

        Tree(Tree&& rhs) = delete;

        Tree& operator=(const Tree& rhs) = delete;

        Tree& operator=(Tree&& rhs) = delete;

        ~Tree()
        {
            if (root_->left_)
                CleanTree(root_->left_);

            if (root_->right_)
                CleanTree(root_->right_);

            CleanTree(root_);
        }



        void TreeInsert(int data);

        void CleanTree(Node* node);

        void Dump(Node* node) const;

};

void Tree::TreeInsert(int data)
{
    Node* x = root_;

    Node* y = nullptr;

    while (x != nullptr)
    {
        y = x;

        if (data < x->data_)
            x = x->left_;

        else if (data > x->data_)
            x = x->right_;
    }

    x = new Node(data);

    if (y == nullptr)
        root_ = x;

    else if (y->data_ > x->data_)
        y->left_ = x;

    else if (y->data_ < x->data_)
        y->right_ = x;
}

void Tree::Dump(Node* node) const
{
    std::cout << node->data_ << std::endl;

    if (node->left_)
        Dump(node->left_);

    if (node->right_)
        Dump(node->right_);
}

void Tree::CleanTree(Node* node)
{
    delete node;
}

#endif