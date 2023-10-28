struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    void reverse();
};

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    tail = head;
    head = prev;
}