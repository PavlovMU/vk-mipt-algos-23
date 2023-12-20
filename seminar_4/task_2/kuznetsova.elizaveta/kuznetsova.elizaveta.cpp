#include <iostream>
#include <vector>
#include <queue>

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

};

Node *buildTree(std::vector<int> arr, int i) {
    if (i >= arr.size()) {
        return nullptr;
    }

    Node *root = new Node(arr[i]);
    root->left  = buildTree(arr, 2*i + 1);
    root->right = buildTree(arr, 2*i + 2);

    return root;
}



bool isSymmetricBFS(Node *root) {
    std::vector<Node *> nodes{root};

    while (nodes.size() != 0) {
        std::vector<Node *> queue;

        for (auto current : nodes) {
            if (current->left) {
                queue.push_back(current->left);
            }  
            if (current->right) {
                queue.push_back(current->right);
            }
        }


        for (size_t i = 0; i < queue.size(); ++i) {
            std::cout << queue[i]->data << " ";
        }
        std::cout << std::endl;
    
        for (size_t i = 0, j = queue.size() - 1; i < queue.size() / 2; ++i, j--) {
            if (queue[i]->data != queue[j]->data) {
                return false;
            }
        }

        nodes.clear();
        for (auto current : queue) {
            nodes.push_back(current);
        }
    }
    return true;
}

int main() {
    size_t len;
    std::cin >> len;
    std::vector<int> arr(len);

    for (size_t i = 0; i < len; ++i) {
        std::cin >> arr[i];
    } 

    std::cout << std::endl << std::endl;

    Node *root = buildTree(arr, 0);
    std::cout << isSymmetricBFS(root) << std::endl;


}