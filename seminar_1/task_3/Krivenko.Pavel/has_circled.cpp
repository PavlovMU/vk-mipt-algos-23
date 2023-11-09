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

int main(){

    //------------------TEST_1------------------//

    struct Node first1 = {1, nullptr};
    struct Node second1 = {2, nullptr};
    struct Node third1 = {3, nullptr};
    struct Node fourth1 = {4, nullptr};

    struct Node* head1 = &first1;
    head1->next = &second1;
    head1->next->next = &third1;
    head1->next->next->next = &fourth1;
    
    print_list(head1);
    std::cout << hasCicle(head1) << std::endl;

    std::cout << std::endl;
    
    //------------------TEST_2------------------//
    struct Node first2 = {1, nullptr};
    struct Node second2 = {2, nullptr};
    struct Node third2 = {3, nullptr};
    struct Node fourth2 = {4, nullptr};

    struct Node* head2 = &first2;
    struct Node* fourth_ = &fourth2;
    head2->next = &second2;
    head2->next->next = &third2;
    head2->next->next->next = &fourth2;
    fourth_->next = &second2;

    print_list(head2);
    std::cout << hasCicle(head2) << std::endl;

    return 0;
}