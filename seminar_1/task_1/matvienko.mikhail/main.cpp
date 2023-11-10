#include <iostream>

struct node {
    int data_;
    node* next_;

    node(int data = 0, node* next = nullptr) : data_(data), next_(next) {}
};

class linked_list_int {

    public:
        node* head_;
        node* tail_;

    public:
    linked_list_int(node* head = nullptr) : head_(head) { tail_ = head; }
};

void add_node(linked_list_int &List, int data) {
    
    node* new_node = new(node);
    new_node->data_ = data;
    List.tail_->next_ = new_node;
    List.tail_ = new_node;
    new_node->next_ = nullptr;
}

void print(linked_list_int &List) {
    node* head_l = List.head_;
    while (head_l != nullptr) {
        std::cout << head_l->data_ << "  ";
        head_l = head_l->next_;
    }
    delete head_l;
}

void remove_elts(linked_list_int &List, int val) {
    node* dummy = new(node);
    dummy->next_ = List.head_;
    node* prev = new(node);
    prev = nullptr;

    for (node* cur = List.head_; cur != nullptr; cur = cur->next_) {
        if (cur->data_ == val) {
            if (prev == nullptr) {  //delete head
                dummy->next_ = cur->next_;
            } else {                //delete not head
                prev->next_ = cur->next_;
            }
        } else {
            prev = cur;
        }
    }

    List.head_ = dummy->next_;
    List.tail_ = prev;

}

int main() {

    node* head = new(node);

    linked_list_int List(head);
    int count;
    std::cout << "Enter count of elts of list" << std::endl;
    std::cin >> count;
    int data;

    if (count > 0) {
        std::cin >> data;
        head->data_ = data;
        head->next_ = nullptr;
        linked_list_int List(head);
    }

    for (int i = 1; i < count; i++) {
        std::cin >> data;
        add_node(List, data);
    }

    print(List);
    std::cout << std::endl;
    
    int val;
    std::cout << "Enter value for removing" << std::endl;
    std::cin >> val;
    remove_elts(List, val);
    print(List);

}
