#include <iostream>
#include <vector>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int value;

    TreeNode() {
        left = nullptr;
        right = nullptr;
        value = 0;
    }
    TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        this->left = left;
        this->right = right;
        this->value = value;
    }
};

long maxMinMultiplication(std::vector<long> data) {
    if (data.size() < 3) {
        return -1;
    }
    int min_ind = 1;
    int max_ind = 2;
    /* int i = 0;
    while (true) {
        int min_ind_tmp = 2 * i + 1;
        if (min_ind_tmp < data.size()) {
            min_ind = min_ind_tmp;
            i = min_ind_tmp;
            continue;
        }
        break;
    } */
    for (int i = 1; i < data.size(); i = 2 * i + 1) {
        min_ind = i;
    }
    for (int i = 1; i < data.size(); i = 2 * i + 2) {
        max_ind = i;
    }
    long result = data[min_ind] * data[max_ind];
    return result;
}

