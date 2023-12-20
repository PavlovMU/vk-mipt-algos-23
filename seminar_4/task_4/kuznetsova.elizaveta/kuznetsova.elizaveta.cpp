#include <iostream>
#include <algorithm>
#include <vector>

class Node {
    int data;
    Node *left;
    Node *right;
}; 
// работает только для идеально сбалансированного дерева 
int maxMinMultiplication(std::vector<int> arr) {
    if (arr.size() < 3) {
        return -1;
    }
    int min_index = 1; 
    int max_index = 2;

    for (int i = 1; i < arr.size(); i = 2*i + 1) {
        if (arr[i] <= arr[min_index]) {
            min_index = i;
        }
    }    

    for (int i = 2; i < arr.size(); i = 2*i + 2) {
        if (arr[i] >= arr[max_index]) {
            max_index = i;
        }
    }
    

    int result = arr[min_index] * arr[max_index];

    return result;
}


int main() {
    size_t len;
    std::cin >> len;
    std::vector<int> arr(len);

    for (size_t i = 0; i < len; ++i) {
        std::cin >> arr[i];
    } 

    std::cout << std::endl;
    std::cout << maxMinMultiplication(arr) << std::endl;
    

}