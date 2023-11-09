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

bool has_cycle(struct Node *head) {
    struct Node *rabbit = head;
    struct Node *turtle = head;

    while (1) {
        if (rabbit == NULL)
            return 0;
        if (rabbit->next == NULL)
            return 0;
        rabbit = rabbit->next->next;
        turtle = turtle->next;
        if (turtle == rabbit) 
            return 1;
//        std::cout << turtle->data << rabbit->data << std::endl;
    }
    return 0;
}

int main() {
    struct Node *head = node_create(1);
    struct Node *node_2 = node_create(2);
    struct Node *node_3 = node_create(3);
    head->next = node_2;
    node_2->next = node_3;
    node_3->next = head;

    std::cout << has_cycle(head) << std::endl;
    return 0;
}