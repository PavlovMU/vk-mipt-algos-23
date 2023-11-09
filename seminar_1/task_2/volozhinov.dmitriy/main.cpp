#include <iostream>

struct Node {
    struct Node *next;
    int data;
};

struct Node *node_create(int head_val) {
    struct Node *head = new struct Node;
    head->data = head_val;
    return head;
}

struct Node *reverse_list(struct Node *head) {
    struct Node *current = head;
    struct Node *prev;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    struct Node *head = node_create(1);
    struct Node *node_2 = node_create(2);
    struct Node *node_3 = node_create(3);
    head->next = node_2;
    node_2->next = node_3;

    head = reverse_list(head);
    std::cout << head->data << head->next->data << head->next->next->data << std::endl;
    return 0;
}