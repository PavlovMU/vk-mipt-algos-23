struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    bool hasCycle();
};

bool LinkedList::hasCycle() {
    if (head == nullptr || head->next == nullptr)
        return false;

    Node* slow = head;
    Node* fast = head->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}