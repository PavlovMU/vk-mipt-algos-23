 struct Node {
      int val;
      Node *next;
      Node() : val(0), next(nullptr) {}
      Node(int x) : val(x), next(nullptr) {}
 };

Node* reverseList(Node* head) {
        Node* current = head;
        Node* prev = nullptr;
        while(current != nullptr) {
            Node* forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        head = prev;
        return head;
    }
