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

bool has_cycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}