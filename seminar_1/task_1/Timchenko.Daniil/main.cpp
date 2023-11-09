struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    void eraseVal(int value);
};

void LinkedList::eraseVal(int value) {
    Node* cur = head;
    Node* prev = nullptr;

    while (cur != nullptr) {
        if (cur->data == value) {
            if (prev == nullptr) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    return;
}