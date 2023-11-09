#include <iostream>

struct Node{
    int data;
    Node *next;
};

bool is_empty(Node* head) {
    return head == nullptr;
}

bool hasCicle(Node* head){
    if (head == nullptr || head->next == nullptr){
        return false;
    }
    Node* slow = head;
    Node* fast = head->next;

    while (slow != fast){
        if (fast == nullptr || fast->next == nullptr){
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

void print_list(Node* head){
    if (hasCicle(head)){
        std::cout << "Your list is circled" << std::endl;
        return;
    }
    if (is_empty(head)) return;
    Node* p = head;
    while (p) { // p != nullptr
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
}

Node *reverse(Node *head)
{
    Node *phead = nullptr; 

    while (head != nullptr)
    {
        Node *p = head->next;
        head->next = phead;
        phead = head;
        head = p;
    }

    return phead;
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
    
    std::cout << "Initial list: ";
    print_list(head);
    
    auto head_new = reverse(head);
    std::cout << "Reversed list: ";
    print_list(head_new);

    return 0;
}