#include <iostream>

struct Node {
    Node* next;
    int value;

    Node() {
        next = nullptr;
        value = 0;
    }
    Node(int value) {
        next = nullptr;
        this->value = value;
    }
};

Node* reverse_list(Node* head) {
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* current = head;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}