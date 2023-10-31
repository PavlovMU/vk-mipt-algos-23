#include <iostream>
#include <cstdlib>

struct Node {
    struct Node *next;
    int data;
};

struct Node *node_create(int head_val) {
    struct Node *head = (struct Node *)calloc(1, sizeof(struct Node *));
    head->data = head_val;
    return head;
}

struct Node *Remove(struct Node *head, int val) {
    struct Node dummy = {head, 0};
    struct Node *current = head;
    struct Node *prev = &dummy;
    while (current != NULL) {
        if (current->data == val) {
            struct Node *save = prev->next;
            prev->next = current->next;
            free(save);
        }
        else
            prev = current;
        current = current->next;
    }
    return dummy.next;
}

int main() {
    struct Node *head = node_create(1);
    struct Node *node_2 = node_create(2);
    struct Node *node_3 = node_create(3);
    head->next = node_2;
    node_2->next = node_3;

    Remove(head, 2);
    std::cout << head->data << head->next->data << std::endl;
    return 0;
}