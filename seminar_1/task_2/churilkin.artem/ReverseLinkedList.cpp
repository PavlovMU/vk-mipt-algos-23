struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    if (head == nullptr or head->next == nullptr) 
    {
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    return 0;
}