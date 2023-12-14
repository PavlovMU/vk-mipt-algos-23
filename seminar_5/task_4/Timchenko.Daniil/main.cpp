#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

int max_sum = INT_MIN;
vector<int> max_path;

pair<int, vector<int>> dfs(Node* node) {
    if (!node) {
        vector<int> x;
        return {0, x};
    }

    pair<int, vector<int>> left = dfs(node->left);
    pair<int, vector<int>> right = dfs(node->left);

    vector<int> cur_max_path;
    int cur_max_sum;

    if (left.first > right.first) {
        cur_max_path = left.second;
    } else {
        cur_max_path = right.second;
    }
    cur_max_path.push_back(node->val);
    cur_max_sum = max(left.first, right.first) + node->val;

    if (left.first + node->val + right.first > max_sum) {
        max_sum = left.first + node->val + right.first;
        max_path = left.second;
        max_path.push_back(node->val);
        max_path.insert(max_path.begin(), right.second.begin(), max_path.end());
    }

    return {cur_max_sum, cur_max_path};
}

vector<int> find_max_path_sum(Node* root) {
    dfs(root);
    return max_path;
}