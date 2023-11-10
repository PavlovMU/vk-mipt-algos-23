#include <iostream>

struct Node{
    int data;
    Node *next;
};

bool is_empty(Node* head) {
    return head == nullptr;
}

void print_list(Node* head){
    if (is_empty(head)) return;
    Node* p = head;
    while (p) { // p != nullptr
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
}

void Remove_El(Node* head, int val){
    if (is_empty(head)) return;
    
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->data != val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        std::cout << "This element does not exist" << std::endl;

        return;
    }
    slow->next = fast->next;
    // free(fast);
}

int main(){

    //------------------TEST------------------//

    struct Node first = {1, nullptr};
    struct Node second = {2, nullptr};
    struct Node third = {3, nullptr};
    struct Node fourth = {4, nullptr};

    struct Node* head = &first;
    head->next = &second;
    head->next->next = &third;
    head->next->next->next = &fourth;
    
    print_list(head);
    std::cout << is_empty(head) << std::endl;

    Remove_El(head, 4);
    print_list(head);

    return 0;
}
