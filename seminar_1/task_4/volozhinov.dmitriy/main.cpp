#include <iostream>
#include <vector>

struct Node {
    struct Node *next;
    int data;
};

struct Node *node_create(int head_val) {
    struct Node *head = new struct Node;
    head->data = head_val;
    return head;
}

std::vector<int> find_numbers(std::vector<int> array, int sum) {
    int i = 0;
    int j = array.size() - 1;
    std::vector<int> indexes(2);
    while (1) {
        if (array[i] + array[j] < sum)
            i++;
        else if (array[i] + array[j] > sum)
            j--;
        else if (array[i] + array[j] == sum)
            break;
    }
    indexes[0] = i;
    indexes[1] = j;
    return indexes;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> i = find_numbers(a, 7);
    std::cout << i[0] << " " << i[1] << std::endl;
    return 0;
}