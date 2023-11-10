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

void reverse_list(linked_list_int &List) {
    node* prev;
    node* cur;
    prev = nullptr;
    cur = List.head_;
    node* tmp = new(node);
    while (cur != nullptr) {
        tmp = cur->next_;
        cur->next_ = prev;
        prev = cur;
        cur = tmp;
    }
    delete tmp;
    List.tail_ = List.head_;
    List.head_ = prev;
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

    reverse_list(List);
    print(List);

}